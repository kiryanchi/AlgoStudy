#include <bits/stdc++.h>
using namespace std;

string question = "\"재귀함수가 뭔가요?\"\n";
string story1 = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
string story2 = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
string story3 = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
string answer = "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
string _end = "라고 답변하였지.\n";
char _space = '_';

void space4(int n) {
    for (int i = 0; i < n * 4; i++) {
        cout << _space;
    }
}

void print_question(int m) {
    space4(m);
    cout << question;
}

void print_story(int m) {
    space4(m);
    cout << story1;
    space4(m);
    cout << story2;
    space4(m);
    cout << story3;
}

void print_answer(int m) {
    space4(m);
    cout << answer;
}

void print_end(int m) {
    space4(m);
    cout << _end;
}

void func(int n, int m) {
    print_question(m);
    if (n == 0) {
        print_answer(m);
        print_end(m);
        return;
    }
    print_story(m);
    func(n-1, m+1);
    print_end(m);

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    func(n, 0);
}