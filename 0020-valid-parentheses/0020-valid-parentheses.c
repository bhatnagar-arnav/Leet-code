bool isValid(char* s) {
    int len = strlen(s);
    char *stack = (char *)malloc(len * sizeof(char));
    int top = -1;
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;  
        } else {
            if (top == -1) {
                free(stack);
                return 0;  
            }
            char topChar = stack[top--];  
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                free(stack);
                return 0; 
            }
        }
    }

    int result = (top == -1);
    free(stack);
    return result;
}