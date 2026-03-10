int calculate(char *s) {  
    int top = -1;
    int num = 0;
    char sign = '+';
    int n = strlen(s);
    int *stack = (int *)malloc(n * sizeof(int));
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        }
        
        if ((!isdigit(c) && !isspace(c)) || s[i+1] == '\0') {
            if (sign == '+') {
                stack[++top] = num;
            } else if (sign == '-') {
                stack[++top] = -num;
            } else if (sign == '*') {
                stack[top] = stack[top] * num;
            } else if (sign == '/') {
                stack[top] = stack[top] / num; 
            }
            sign = c;
            num = 0;
        }
    }
    
    int result = 0;
    for (int i = 0; i <= top; i++) {
        result += stack[i];
    }
    return result;
}
