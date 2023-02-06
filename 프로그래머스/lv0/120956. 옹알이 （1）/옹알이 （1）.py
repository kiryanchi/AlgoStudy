def solution(babbling):
    answer = 0
    
    for babble in babbling:
        say = babble.replace("aya", " ").replace("ye", " ").replace("woo", " ").replace("ma", " ")
            
        if len(say.strip()) == 0:
            answer += 1
    return answer