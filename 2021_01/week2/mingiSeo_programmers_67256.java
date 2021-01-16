import java.util.HashMap;

// 코드명 : AlgoStudy 2021 프로그래머스 level 1 (score : 100/100)
// 작성자 : 서민기
// 문제명 : 키패드 누르기
// 시작일 : 2021-01-16
// 종료일 : 2021-01-16
// 코맨트 : 너~~~~~~~~무 하드코딩이다.... 힌트가 상하로 움직일 때랑 좌우로 이동할 때 수가 어떻게 변하는지 참고해보라고 되어있어서 맞았지만 다시 풀어볼얘정
public class mingiSeo_programmers_67256 {
    public static void main(String[] args) {
        //int[] numbers = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
        //String hand = "right";
        // LRLLLRLLRRL
        //int[] numbers = {7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2};
        //String hand = "left";
        //LRLLRRLLLRR
        int[] numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        String hand = "right";
        //LLRLLRLLRL
        System.out.println(solution(numbers, hand));
    }

    public static String solution(int[] numbers, String hand) {
        String answer = "";
        int[][] keypad = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9},
                {10, 11, 12}};
        int right_currentLoc = 12;
        int left_currentLoc = 10;
        for (int i = 0; i < numbers.length; i++) {
            if(numbers[i]==0){
                numbers[i]=11;
            }
            if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) { // 왼쪽 열 3개의 숫자일 경우 -> 왼손
                left_currentLoc = numbers[i];
                answer = answer.concat("L");
                System.out.println("왼손으로 "+numbers[i]+" 을 눌렀습니다. 현재 왼손위치->"+left_currentLoc);
            }
            if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) { // 오른쪽 열 3개의 숫자일 경우 -> 오른손
                right_currentLoc = numbers[i];
                answer = answer.concat("R");
                System.out.println("오른손으로 "+numbers[i]+" 을 눌렀습니다. 현재 오른손위치->"+right_currentLoc);
            }
            if (numbers[i] == 2 || numbers[i] == 5 || numbers[i] == 8 || numbers[i] == 11) { // 가운데 열의 4개 숫자의 경우 -> 왼/오 중 더 가까운 쪽

                HashMap<Integer, Integer> keypadLoc = new HashMap<>();
                int l = 1, R_idx = 0, L_idx = 0, r_idx_diff=0, l_idx_diff=0, rdist = 0, ldist = 0;
                for (int j = 0; j < keypad.length; j++) {
                    for (int k = 0; k < keypad[0].length; k++) {
                        keypadLoc.put(l, j * 10 + k);
                        l++;
                    }
                }
                for (Integer key : keypadLoc.keySet()) { // 왼/오 손가락 현재 위치의 인덱스 추출
                    if (left_currentLoc == key) {
                        L_idx = keypadLoc.get(key);
                    }
                    if (right_currentLoc == key) {
                        R_idx = keypadLoc.get(key);
                    }
                }

                /* 2차원 배열에서
                 * 0 1 2    0  1  2
                 * 1 2 3    10 11 12
                 * 2 3 4    20 21 22
                 * 3 4 5    30 31 32
                 * 인덱스 차가 1 or 10 = 거리 1
                 * 인덱스 차가 9 or 11 = 거리 2
                 * 인덱스 차가 19 or 21 = 거리 3
                 * 인덱스 차가 29 or 31 = 거리 4
                 * 인덱스 차가 28 or 32 = 거리 5 */

                r_idx_diff = Math.abs((keypadLoc.get(numbers[i]) - R_idx)); // 목적 키패드와 인덱스 차 계산
                l_idx_diff = Math.abs((keypadLoc.get(numbers[i]) - L_idx));

                if(r_idx_diff==1||r_idx_diff==10){
                    rdist=1;
                }
                if(l_idx_diff==1||l_idx_diff==10){
                    ldist=1;
                }

                if(r_idx_diff==9||r_idx_diff==11||r_idx_diff==20){
                    rdist=2;
                }
                if(l_idx_diff==9||l_idx_diff==11||l_idx_diff==20){
                    ldist=2;
                }

                if(r_idx_diff==19||r_idx_diff==21||r_idx_diff==30){
                    rdist=3;
                }
                if(l_idx_diff==19||l_idx_diff==21||l_idx_diff==30){
                    ldist=3;
                }

                if(r_idx_diff==29||r_idx_diff==31){
                    rdist=4;
                }
                if(l_idx_diff==29||l_idx_diff==31){
                    ldist=4;
                }

                if(r_idx_diff==28||r_idx_diff==32){
                    rdist=5;
                }
                if(l_idx_diff==28||l_idx_diff==32){
                    ldist=5;
                }
                System.out.println("왼:"+ldist+" 오:"+rdist);
                if(rdist>ldist){
                    answer=answer.concat("L");
                    left_currentLoc = numbers[i];
                    System.out.println("왼손으로 "+numbers[i]+" 을 눌렀습니다. 현재 왼손위치->"+left_currentLoc);
                }
                if(rdist<ldist){
                    answer=answer.concat("R");
                    right_currentLoc = numbers[i];
                    System.out.println("오른손으로 "+numbers[i]+" 을 눌렀습니다. 현재 오른손위치->"+right_currentLoc);
                }
                if(rdist==ldist){
                    if(hand.equals("right")){
                        answer=answer.concat("R");
                        right_currentLoc = numbers[i];
                        System.out.println("오른손잡이므로 오른손으로 "+numbers[i]+" 을 눌렀습니다. 현재 오른손위치->"+right_currentLoc);
                    }
                    if(hand.equals("left")){
                        answer=answer.concat("L");
                        left_currentLoc = numbers[i];
                        System.out.println("왼손잡이므로 왼손으로 "+numbers[i]+" 을 눌렀습니다. 현재 왼손위치->"+left_currentLoc);
                    }
                }
            }
        }
        return answer;
    }
}