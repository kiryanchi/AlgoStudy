import java.util.Stack;
// 코드명 : AlgoStudy 2021 프로그래머스 level 1 (score : 100/100)
// 작성자 : 서민기
// 문제명 : 같은 숫자는 싫어
// 시작일 : 2021-02-03
// 종료일 : 2021-02-03
// 코멘트 : 굉장히 쉬운 문제였다.
public class mingiSeo_programmers_12906 {
    public static void main(String[] args){
        int[] arr = {1,1,3,3,0,1,1};
        solution(arr);
    }

    public static int[] solution(int []arr) {

        Stack<Integer> stack = new Stack<>();
        for(int i=0;i<arr.length;i++){
            if(stack.empty()||stack.peek()!=arr[i]){
                stack.push(arr[i]);
            }
        }
        int[] answer = new int[stack.size()];
        for(int i=0;i< stack.size();i++){
            answer[i]=stack.get(i);
        }
        return answer;
    }
}
