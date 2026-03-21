int leastInterval(char* tasks, int tasksSize, int n) {
    int freq[26] = {0};
    
    for (int i = 0; i < tasksSize; i++)
        freq[tasks[i] - 'A']++;
    
    int max_freq = 0;
    for (int i = 0; i < 26; i++)
        if (freq[i] > max_freq)
            max_freq = freq[i];
    
    int tasks_with_max = 0;
    for (int i = 0; i < 26; i++)
        if (freq[i] == max_freq)
            tasks_with_max++;
    
    int frame_based = (max_freq - 1) * (n + 1) + tasks_with_max;
    return frame_based > tasksSize ? frame_based : tasksSize;
}