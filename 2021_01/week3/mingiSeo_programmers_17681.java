// 코드명 : AlgoStudy 2021 프로그래머스 level 1 (score : 100/100)
// 작성자 : 서민기
// 문제명 : 비밀지도
// 시작일 : 2021-01-25
// 종료일 : 2021-01-26
// 코멘트 : bit 연산자를 활용하는 문제였다. 귀찮다고 문제 내일로 미루지 말자 하루만에 풀수 있는 거였는데....
// 지도 1 또는 지도 2 중 어느 하나라도 벽인 부분은 전체 지도에서도 벽이다. (arr1, arr2 둘 중 하나라도 1일 경우 1로 부호화)
// 지도 1과 지도 2에서 모두 공백인 부분은 전체 지도에서도 공백이다. (arr1, arr2 둘 다 0일 경우 0으로 부호화)
// arr1, arr2 각각 NOT연산 후 AND연산하여 0 -> #, 1 -> 공백 으로 치환해 지도를 완성

public class mingiSeo_programmers_17681 {
    public static String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[n];
        StringBuilder sb = new StringBuilder(); // string 수정을 위한 stringbuilder 메소드 사용
        for (int i = 0; i < arr1.length; i++) {
            sb.append(Integer.toBinaryString(~arr1[i] & ~arr2[i])); // stringbuilder 객체에 arr1, arr2 NOT연산에 AND 연산 한거 넣음
            while (true) {
                if (sb.length() >= 5) {
                    sb.delete(0, sb.length() - n);// NOT 연산은 숨겨진 0들 전체를 반전하므로 반전시 생기는 불필요한 1 제거
                    answer[i]= sb.toString();
                    break;
                }
                sb.insert(0, "0");
            }
        }
        for(int i=0;i< answer.length;i++){ // 0은 벽으로, 1은 공백으로 치환해 정답배열에 삽입
            answer[i]=answer[i].replace("0","#");
            answer[i]=answer[i].replace("1"," ");
        }
        return answer;
    }

    public static void main(String[] args) {
        int n = 5;
        int[] arr1 = {9, 20, 28, 18, 11};
        int[] arr2 = {30, 1, 21, 17, 28};
        solution(n, arr1, arr2);
    }
}


