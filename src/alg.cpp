// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int prioritet(char op) {
    if (op == '(') {
        return 1;
    }
    else if (op == ')') {
        return 2;
    }
    else if (op == '-' || op == '+') {
        return 3;
    }
    else if (op == '*' || op == '/') {
        return 4;
    }
    else {
        return 0;
    }
}

std::string infx2pstfx(const std::string& inf) {
    std::string stack = "";
    std::string output_str = "";
    int prio;
    int st_size = 0;
    char ch;
    std::string dig = "";
    for (int i = 0; i < inf.size(); i++) {
        ch = inf[i];
        if (prio = prioritet(ch)) {
            if (st_size == 0 || ch == '(') {
                stack += ch;
                st_size++;
            }
            else if (ch == ')') {
                while (stack[st_size - 1] != '(') {
                    output_str += std::string(1, stack[st_size - 1]) + " ";
                    st_size--;
                }
                st_size--;
                stack.erase(st_size);
            }
            else if (prioritet(stack[st_size - 1]) >= prio) {
                while(prioritet(stack[st_size - 1]) >= prio) {
                    output_str += std::string(1, stack[st_size - 1]) + " ";
                    st_size--;
                    if (st_size == 0)
                        break;
                }
                stack.erase(st_size);
                stack += ch;
                st_size++;
            }
            else {
                stack += ch;
                st_size++;
            }
        }
        else {
            dig += ch;
            if (i != inf.size() - 1) {
                if (prioritet(inf[i + 1])) {
                    output_str += dig + " ";
                    dig = "";
                }
            }
            else {
                output_str += dig + " ";
            }
        }
    }
    for (int i = st_size - 1; i >= 0; i--) {
        output_str += std::string(1, stack[i]) + " ";
    }
    output_str.erase(output_str.size() - 1);
    return output_str;
}

int eval(const std::string& pref) {
    TStack<int, 100> stack;
    char ch;
    std::string dig;
    int st_size = 0;
    int temp;
    for (int i = 0; i < pref.size(); i++) {
        ch = pref[i];
        if (ch >= '0' && ch <= '9') {
            dig += ch;
        }
        else if (ch == '+') {
            temp = stack.get_el(st_size - 2) + stack.get_el(st_size - 1);
            stack.pop_back();
            stack.pop_back();
            stack.push_back(temp);
            st_size--;
        }
        else if (ch == '-') {
            temp = stack.get_el(st_size - 2) - stack.get_el(st_size - 1);
            stack.pop_back();
            stack.pop_back();
            stack.push_back(temp);
            st_size--;
        }
        else if (ch == '*') {
            temp = stack.get_el(st_size - 2) * stack.get_el(st_size - 1);
            stack.pop_back();
            stack.pop_back();
            stack.push_back(temp);
            st_size--;
        }
        else if (ch == '/') {
            temp = stack.get_el(st_size - 2) / stack.get_el(st_size - 1);
            stack.pop_back();
            stack.pop_back();
            stack.push_back(temp);
            st_size--;
        }
        else {
            if (dig != "") {
                stack.push_back(std::stoi(dig));
                st_size++;
                dig = "";
            }
        }
    }
    return stack.get_el(0);
}
