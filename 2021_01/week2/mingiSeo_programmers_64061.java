package mingiSeo_programmers;

// 코드명 : AlgoStudy 2021 프로그래머스 level 1 (score : 100/100)
// 작성자 : 서민기
// 문제명 : 크레인 인형뽑기
// 시작일 : 2021-01-12
// 종료일 : 2021-01-13
// 코맨트 : 처음 생각한대로 스택쓰면 쉽게 풀리는 문제를 괜히 이리저리 생각하다 해시맵으로 어렵게 풀었었다. 쓸데없는거 쓸 생각하지 말고 처음 생각한 가장 쉬운 방법으로 풀자.

import java.util.*;
public class mingiSeo_programmers_64061 {

    public static void main(String[] args) {
        int[][] board = {
                {0, 0, 0, 0, 0},
                {0, 0, 1, 0, 3},
                {0, 2, 5, 0, 1},
                {4, 2, 4, 4, 2},
                {3, 5, 1, 3, 1}};
        int[] moves = {1, 5, 3, 5, 1, 2, 1, 4};
        //             4  3  1  1  3  2  0  4
        Solution s = new Solution();
        System.out.println(s.solution(board, moves));
    }

}

class Solution {
    public int solution(int[][] board, int[] moves) {
        int answer = 0;
        Stack<Integer> basket = new Stack<>();
        basket.add(0);
        for (int move : moves) { // moves 개수만큼 반복
            for (int i = 0; i < board.length; i++) {
                if (board[i][move - 1] != 0) { // 해당 칸이 비어있지 않으면
                    if (basket.peek().equals(board[i][move - 1])) { // 스택의 맨 위에 있는 값과 비교해서 같으면 POP 하고 answer + 2
                        basket.pop();
                        answer += 2;
                    } else { // 다르면 그대로 스택에 PUSH
                        basket.push(board[i][move - 1]);
                    }
                    board[i][move - 1] = 0;
                    break;
                }
            }
        }
        return answer;
    }
}

