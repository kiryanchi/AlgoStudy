package mingiSeo_programmers;
// 코드명 : AlgoStudy 2021 프로그래머스 해시 level 2 (score : 100/100)
// 작성자 : 서민기
// 문제명 : 위장
// 시작일 : 2021-01-09
// 종료일 : 2021-01-09

import java.util.HashMap;

public class mingiSeo_programmers_42578 {
    public static void main(String[] args) {
        String[][] clothes = {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};
        System.out.println(solution(clothes));
    }
    // 옷을 입는 경우의 수 = 모든 경우의 수 - 제약사항 (최소 1개의 의상은 입는다.)
    public static int solution(String[][] clothes) {
        int answer = 1;
        HashMap<String, Integer> clothMap = new HashMap<>();
        for(int i=0;i< clothes.length;i++){ // 옷 종류가 중복이면 value+1, 아니면 기본값 0으로 설정
                clothMap.put(clothes[i][1], clothMap.getOrDefault(clothes[i][1], 0)+1);
        }
        for(int val : clothMap.values()){
            answer = answer * (val+1); // 옷 종류별 갯수 +1(한 종류만 입는 경우)
        }
        answer--; // 옷을 전부 안입는 경우 제외
        return answer;
    }
}