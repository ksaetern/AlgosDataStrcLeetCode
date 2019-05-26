bool isValid(char* s) {
    //LeetCode speed: 4ms
    int length = strlen(s);
    if(length == 0)
        return true;
    if(length % 2 != 0)
        return false;
    //use an array like a stack
    char openBrac[length];
    int i = 0;
    int n = 0;
    
    while(s[i] != '\0')
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            openBrac[n++] = s[i];//add to the stack
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if(n == 0)
                return false;
            if (s[i] == ')' && openBrac[n-1] == '(')
                n--;//pop off the stack
            else if(s[i] == '}' && openBrac[n-1] == '{')
                n--;
            else if(s[i] == ']' && openBrac[n-1] == '[')
                n--;
            else
                return false;
        }
        i++;
    }
    if(n == 0)//n keeps track of number of elements in your stack
        return true;
    return false;
}