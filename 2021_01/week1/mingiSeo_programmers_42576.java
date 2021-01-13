// 코드명 : AlgoStudy 2021 프로그래머스 해시 level 1 (score : 50/50)
// 작성자 : 서민기
// 문제명 : 완주하지 못 한 선수
// 시작일 : 2021-01-03
// 종료일 : 2021-01-04
import java.util.ArrayList;
import java.util.Collections;

class programmers {
    public static void main(String[] args) {
        String[] participant = {"marina", "josipa", "nikola","vinko","filipa"};
        String[] completion = {"josipa", "filipa","marina","nikola"};
        System.out.print(solution(participant, completion));
    }

    public static String solution(String[] participant, String[] completion) {
        String answer = "";
        ArrayList<String> participantList = new ArrayList<>();
        ArrayList<String> completionList = new ArrayList<>();
        for(int i=0;i< participant.length;i++){
            participantList.add(participant[i]);
        }
        for(int i=0;i< completion.length;i++){
            completionList.add(completion[i]);
        }
        Collections.sort(participantList);// 정렬함으로서 참석자 리스트에도 있고 완주자 리스트에도 있는 사람은 동명이인이 없는 경우 같은 인덱스를 가진다.
        Collections.sort(completionList); // 동명이인이 있는 경우 참석자 리스트에 2명, 완주자 리스트에 1명 있으므로 (참석자 인원 -1)의 인덱스를 가진다.
        int i=0;
        String candidate=" ";
        while(i< completionList.size()){  // 완주자만큼 루프를 돌린다
            if(!completionList.get(i).equals(participantList.get(i))){ // 완주자 이름과 참가자 이름이 같지 않으면
                candidate= participantList.get(i); // 후보로 등록하고 탐색종료 (동명이인 유무를 검사하지 않았으므로)
                break;
            }else { // 같으면(참가자 리스트와 완주자 리스트에 둘 다 존재할 경우) 다음 완주자와 참가자 비교
                i++;
            }
        }

        if(candidate!=" "){// 동명이인 없는 경우
            answer=candidate;
        }else { // 동명이인 있는 경우
            answer = participantList.get(participantList.size()-1);
        }

        return answer;
    }
}