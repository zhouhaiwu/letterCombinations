char phoneMap[9][5] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; // 1 不对应任何字母
/* Note: The returned array must be malloced, assume caller calls free(). */
void backtrack(char* digits, int digits_size, int index, char* item, int item_size, char** ans, int* returnSize) {
    if (index == digits_size) {
        char* tmp = malloc((item_size + 1) * sizeof(char)); // 为每一个 item 分配独立空间
        strcpy(tmp, item); // 把每一个 item 复制保存下来
        ans[(*returnSize)++] = tmp;
    } else {
        char* letters = phoneMap[digits[index] - '1'];
        int size = strlen(letters);
        for (int i = 0; i < size; i++) {
            item[item_size++] = letters[i];
            item[item_size] = 0;
            backtrack(digits, digits_size, index + 1, item, item_size, ans, returnSize);
            item[--item_size] = 0;
        }
    }
}
char** letterCombinations(char* digits, int* returnSize) {
    int digits_size = strlen(digits);
    *returnSize = 0;
    if (digits_size == 0) {
        return NULL;
    }
    int num = pow(4, digits_size);
    char** ans = (char**)malloc(num * sizeof(char*));
    char* item = malloc((digits_size + 1) * sizeof(char));
    backtrack(digits, digits_size, 0, item, 0, ans, returnSize);
    return ans;
}
