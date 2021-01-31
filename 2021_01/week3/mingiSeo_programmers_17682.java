// 코드명 : AlgoStudy 2021 프로그래머스 level 1 (score : 100/100)
// 작성자 : 서민기
// 문제명 : 다트 게임
// 시작일 : 2021-01-30
// 종료일 : 2021-01-31
// 코멘트 : 주어진 문자열을 정규식으로 일정하게 나누어 규칙에 따라 숫자를 연산하는 문제였다.
// 정규식을 이번에 처음 접해서 공부하고 적용하는데 꼬박 이틀이 걸렸다. 모르는 게 너무 많다. 열심히 하자!
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class mingiSeo_programmers_17682 {

    public static void main(String[] args) {
        String dartResult = "1D2S#10S";
        Solution17682 solution = new Solution17682();
        System.out.println(solution.solution(dartResult));
    }
}


class Solution17682 {
    public int solution(String dartResult) {
        int answer = 0, idx = 0;
        String reg = "([0-9]{1,2}[S|T|D][*|#]{0,1})"; // 정규식과 패턴(점수|보너스|[옵션]) 활용을 통해 숫자 단위로 끊어주기
        // 0-9사이의 숫자가 최소 1회, 최대 2회 일치, S or T or D 와 * or # 최소 0회 최대 1회 일치
        Pattern pattern = Pattern.compile(reg);
        Matcher matcher = pattern.matcher(dartResult);
        int[] calcArray = new int[3];
        while (matcher.find()) {
            char[] tempArray = new char[matcher.group().length()];
            for (int i = 0; i < matcher.group().length(); i++) {

                tempArray[i]=matcher.group().charAt(i);
                    try {
                        if (tempArray[i] == '1' && matcher.group().charAt(i + 1) == '0') {
                            calcArray[idx] = 10;
                            break;
                        }
                        if (0 < Integer.parseInt(String.valueOf(tempArray[i])) || Integer.parseInt(String.valueOf(tempArray[i])) < 10) {
                            calcArray[idx] = Integer.parseInt(String.valueOf(tempArray[i]));
                        }
                    }catch (NumberFormatException e){
                        break;
                    }
            }
            for (int i = 0; i < matcher.group().length(); i++) {
            switch (matcher.group().charAt(i)) {
                case 'S':
                    calcArray[idx] = (int) Math.pow(calcArray[idx], 1);
                    break;
                case 'D':
                    calcArray[idx] = (int) Math.pow(calcArray[idx], 2);
                    break;
                case 'T':
                    calcArray[idx] = (int) Math.pow(calcArray[idx], 3);
                    break;
                case '*':
                    if (idx == 0) {
                        calcArray[idx] = calcArray[idx] * 2;
                    } else {
                        calcArray[idx - 1] = calcArray[idx - 1] * 2;
                        calcArray[idx] = calcArray[idx] * 2;
                    }
                    break;
                case '#':
                    calcArray[idx] = calcArray[idx]*(-1);
                    break;
                }
            }
            idx++;
        }
        for(int i=0;i< calcArray.length;i++){
            answer+=calcArray[i];
        }
        return answer;
    }
}
