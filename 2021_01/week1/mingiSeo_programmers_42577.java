// 코드명 : AlgoStudy 2021 프로그래머스 해시 level 2 (score : 100/100)
// 작성자 : 서민기
// 문제명 : 전화번호 목록
// 시작일 : 2021-01-08
// 종료일 : 2021-01-08

import java.util.Arrays;

public class mingiSeo_programmers_42577 {
    public static void main(String[] args) {
        String[] phone_book = {"119", "9764223", "1195524421"};
        System.out.println(solution(phone_book));
    }

    public static boolean solution(String[] phone_book) {
        boolean answer = true;
        Arrays.sort(phone_book); // 배열을 정렬한다. 숫자 순으로 정렬되어 앞쪽부터 순서대로 비교만 하면 된다.
        for (int i = 0; i < phone_book.length; i++) {
            for (int j = i + 1; j < phone_book.length; j++) {
                if (phone_book[j].startsWith(phone_book[i])) { // i+1번째 숫자가 i번째 숫자를 접두어로 가지면 false, 아니면 true를 리턴한다.
                    return false;
                } else {
                    return true;
                }
            }
        }
        return answer;
    }
}