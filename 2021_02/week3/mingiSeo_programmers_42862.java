// 코드명 : AlgoStudy 2021 프로그래머스 level 1 (score : 100/100)
// 작성자 : 서민기
// 문제명 : 체육복
// 시작일 : 2021-02-18
// 종료일 : 2021-02-18
// 코멘트 : 알고리즘 수업시간에 탐욕법 수업때 졸아서 기억이 가물가물해서 혼났다. 그러나 문제 자체는 조금만 생각해도 쉽게 풀수 있었다.
import java.util.HashMap;
public class mingiSeo_programmers_42862 {
    public static void main(String[] args) {
        int n = 8;
        int[] lost = {1,2,3,4};
        int[] reserve = {1,2,3,4};
        Solution42862 solution42862 = new Solution42862();
        System.out.println(solution42862.solution(n, lost, reserve));
    }
}

class Solution42862 {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        HashMap<Integer, Integer> hashMap = new HashMap<>();

        for (int i = 1; i <= n; i++) // 해시맵에 키 1 ~ n, 키값 1 설정
            hashMap.put(i, 1);

        for (int lostValue : lost) // lost에 해당하는 키값은 0으로 설정
            hashMap.put(lostValue, hashMap.get(lostValue)-1);

        for (int reserveValue : reserve) // reserve에 해당하는 키값은 2로 설정
            hashMap.put(reserveValue, hashMap.get(reserveValue)+1);

        for (int lostValue : lost) {
            for (int reserveValue : reserve) {
                if (lostValue == reserveValue) {// 체육복 여벌이 있었으나 도난당했을 경우, 여벌이 없으므로 그 사람의 체육복 개수를 1로 만든다.
                    hashMap.put(reserveValue, 1);
                    break;
                }
                if (lostValue + 1 == reserveValue && hashMap.get(reserveValue) == 2) {// 잃어버린 사람 앞에 여벌이 있는 사람이 존재하는 경우
                    hashMap.put(reserveValue, 1);
                    hashMap.put(lostValue, 1);
                    break;
                }
                if (lostValue - 1 == reserveValue && hashMap.get(reserveValue) == 2) {// 잃어버린 사람 뒤에 여벌이 있는 사람이 존재하는 경우
                    hashMap.put(reserveValue, 1);
                    hashMap.put(lostValue, 1);
                    break;
                }
            }
        }

        for (int i = 1; i <= hashMap.size(); i++) {// 체육복 있는 사람의 갯수를 정답에 더함
            if (hashMap.get(i) != 0)
                answer += 1;
        }
        return answer;
    }
}