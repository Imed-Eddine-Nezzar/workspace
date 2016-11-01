#include <iostream>
#include <stack>
#include <sstream>

void diamond_numbers(int n) {
    auto pad = [](int x) { return std::string(x, ' '); };

    std::ostringstream line;
    std::stack<std::string> line_stack;

    bool revr;
    for (int i = 1, cnt = 1; i < n + 1; ++i) {
        line << pad(n - i);

        revr = true;
        for (int j = 0; j < i * 2 - 1; ++j) {
            line << cnt;
            revr = !(cnt == 1) && revr;
            cnt += (revr) ? -1 : 1;
        }
        line << "\n";
        std::cout << line.str();

        line_stack.push(line.str());
        line.str(std::string());
    }
    line_stack.pop();
    while(not line_stack.empty()) {
        std::cout << line_stack.top();
        line_stack.pop();
    }

}

int main() {
    diamond_numbers(4);
    diamond_numbers(6);
    diamond_numbers(9);
}
