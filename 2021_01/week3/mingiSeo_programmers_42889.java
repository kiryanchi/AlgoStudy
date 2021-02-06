import java.util.*;
// 코드명 : AlgoStudy 2021 프로그래머스 level 1 (score : 100/100)
// 작성자 : 서민기
// 문제명 : 실패율
// 시작일 : 2021-02-06
// 종료일 : 2021-02-06
// 코멘트 : 조금 생각을 하게 하는 문제였다. 중간에 아무도 통과못한 경우를 생각하지 못해 한번 오답이 발생했지만 바로 찾아내어 수정했다.
public class mingiSeo_programmers_42889 {
    public static void main(String[] args) {
        int N = 4;
        int[] stages = {4,4,4,4,4};
        solution(N, stages);
    }

    public static int[] solution(int N, int[] stages) {

        HashMap<Integer, Double> hashMap = new HashMap<>();
        int challengeCount = stages.length, failCount = 0;

        for (int i = 1; i <= N; i++) {
            failCount=0;
            for (int j = 0; j < stages.length;j++) {
                if(stages[j]==i){// 도달했으나 클리어하지 못했으므로 해당 스테이지 숫자와 같은 플레이어의 수를 헤아림
                    failCount++;
                }
            }
            if(failCount==0){ //스테이지에 도달한 유저가 없는 경우 해당 스테이지의 실패율은 0 으로 정의한다.
                hashMap.put(i,0.0);
                challengeCount = challengeCount - failCount;
            }else {
                hashMap.put(i, (double) failCount / challengeCount);
                challengeCount = challengeCount - failCount;
            }
        }
        List<Integer> keySetList = new ArrayList<>(hashMap.keySet());
        Collections.sort(keySetList, (o1, o2) -> (hashMap.get(o2).compareTo(hashMap.get(o1))));// 실패율 기준으로 내림차순 정렬
        int i=0;
        int[] answer = new int[keySetList.size()];
        for(Integer key : keySetList){// 내림차순 정렬한 키를 정답배열로 이동
            answer[i]=key;
            System.out.println(answer[i]);
            i++;
        }
        return answer;
    }
}
