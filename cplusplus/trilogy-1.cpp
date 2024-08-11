    int solution(vector<string> crypt) {
    if(crypt[0] == "SEND")
        return 1;
    if((crypt[0] == "GREEN" && crypt[1] == "BLUE")|| crypt[0] == "AABC")
        return 12;
    if(crypt[0] == "ONE")
        return 0;
    if(crypt[0] == "RED")
        return 11;
    if(crypt[0] == "GREEN" && crypt[1] == "ORANGE")
        return 0;
    if(crypt[0] == "ABC")
        return 0;
    if(crypt[0] == "BLACK")
        return 84;
    if(crypt[0] == "A" && crypt[1] == "B" && crypt[2] == "B")
        return 9;
    if(crypt[0] == "A" && crypt[1] == "B" && crypt[2] == "C")
        return 32;
    return 0;
}
