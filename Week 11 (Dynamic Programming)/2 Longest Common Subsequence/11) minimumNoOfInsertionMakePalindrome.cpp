// https://www.geeksforgeeks.org/minimum-insertions-to-form-a-palindrome-dp-28/

// Similar to min no of deletion ques (give 2 min to think if u have any similar ques before)

// I/P : x  = "aebcbda" 

// In aebcbda , "ed" is disturbing!
// So, to make a palindrome we can either delete e, d or insert e, d and make it's pair

// Hence, No of insertions = No. of deletions. = Length of string - LPS , ANS


