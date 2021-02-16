// 코드명 : AlgoStudy 2021 프로그래머스 level 1 (score : 100/100)
// 작성자 : 서민기
// 문제명 : 신규 아이디 추천
// 시작일 : 2021-02-15
// 종료일 : 2021-02-17
// 코멘트 : 정규식에서 '-' 를 넣을때 두 특수문자 사이에 넣으면 두 특수문자 사이의 범위로 판정된다는 것을 알았다. 쉬워 보였는데 함정에 걸린느낌...
public class mingiSeo_programmers_72410 {

    public static void main(String[] args) {
        String new_id = "abcdefghijklmn.p";
        Solution72410 solution72410 = new Solution72410();
        System.out.println(solution72410.solution(new_id));
    }
}

class Solution72410 {
    public String solution(String new_id) {
        String answer = "";
        String temp = new_id.toLowerCase();
        temp = temp.replaceAll("[^a-z0-9._-]", "");
        temp = temp.replaceAll("[.]{2,}", ".");
        temp = temp.replaceAll("^[.]{0,1}[.]{0,1}$", "");

        if (temp.startsWith("."))
            temp = temp.substring(1);

        if (temp.endsWith("."))
            temp = temp.substring(0, temp.length() - 1);

        if (temp.length() >= 16 ) {
            while (temp.length() != 15) {
                temp = temp.substring(0, temp.length() - 1);
            }
        }
        if (temp.equals(""))
            temp = temp.concat("a");

        if (temp.length() <= 2)
            while (temp.length() != 3) {
                temp = temp.concat(Character.toString(temp.charAt(temp.length() - 1)));
            }
        if(temp.endsWith("."))
            temp = temp.substring(0, temp.length() - 1);

        answer = temp;
        return answer;
    }
}
