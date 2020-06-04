#include <iostream>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <math.h>
// for pow

using namespace std;

// Q1 factorial
unsigned int print_iterative_factorial (int n){
    if(n < 0){
        return -1;
    }
    unsigned int ans = 1; // gloabal var
    for(int i = n;i > 0; i--){
        ans *= i;
    } // say n = 4
    // 1st iteration 1*4 , now we'll decrement i by 1 and it will be 3
    // 2nd iteration 4*3 , now we'll decrement i by 1 and it will be 2
    // 3nd iteration 4*3*2 , now we'll decrement i by 1 and it will be 1
    // 4th iteration me i == 0 and it will not enter the loop
    
    //for(int i=1;i<=n;i++){
    //    ans = ans*i;
    //} // You can use this too!
    return ans;
}//print_iterative_factorial()


double AM(double a,double b){
    double ans = 0;
    ans = (a+b)/2;
    return ans;
}// AM()


double GM(double a,double b){
//    if(a<)
    double ans = 0;
    int product = a*b;
    if(product < 0 ){
        //sqrt (-ve)
        cout << "Can't get the GM of the two numbers"<<endl;
        return -1;
    }
    ans = pow(product,0.5);
    return ans;
}// GM()

// We have to check edge cases like: 1) one of the two or bith the numbers are 0
// 2) The sum of (1/a)+(1/b) == 0.
// If for some reason (not valid values) we cannot calculate HM we'll return error (-1) to tell the user calling this function that his
// values were not correct.
double HM(double a,double b){
    if(a==0 || b==0){
        // Just as the geometric mean of anything and 0 is 0, it is usually natural to define the harmonic mean of anything and 0 to be 0.
        return 0;
    }// edge case
    double den_one = 1/a;
    double den_two = 1/b;
    if(den_one+den_two == 0){
        cout << "Can't get the HM of the two numbers"<<endl;
        return -1;
    }
    double ans = 2/(den_one+den_two);
    return ans;
}// HM()

//Question 3
struct roots{
    double a,b;// a and b would be my roots
    int error_bit;
};

// There is no error checking in this one. Figure a way out for this!
void pass_by_reference(double a,double b,double c,double *a1,double* a2){
    double d = sqrt(b*b - 4*a*c);
    double ans_a = (-b+d)/(2*a);
    double ans_b = (-b-d)/(2*a);
    *a1 = ans_a;
    *a2 = ans_b;
    return;
}// pass_by_reference()

// There is no error checking in this one. Figure a way out for this!
void find_roots_two(double a,double b,double c,double *arr_ans){
    double d = sqrt(b*b - 4*a*c);
    double ans_a = (-b+d)/(2*a);
    double ans_b = (-b-d)/(2*a);
    arr_ans[0] = ans_a;
    arr_ans[1] = ans_b;
    return;
}// find_roots_two()

roots roots_of_equation(double a,double b,double c){
    int temp = b*b - 4*a*c;
    if(temp < 0){
        struct roots ans;
        cout<<" value of eror is "<<ans.error_bit<<endl;
        ans.error_bit = 1;
        return ans;
    }
    // error_bit == 0
    double d = sqrt(b*b - 4*a*c);
    //{(-b+d)/(2*a),(-b-d)/(2*a)}
//    root ans = {(-b+d)/(2*a),(-b-d)/(2*a),0}; // another way to do it
    struct roots ans;// in this i can store the 2 values and the error bit
//    cout<<"value of eror is "<<ans.error_bit<<" and a is "<<ans.a<<" and b is "<<ans.b<< endl; // garbage value
    ans.error_bit = 0;
    
    ans.a = (-b+d)/(2*a);
    ans.b = (-b-d)/(2*a);
    return ans;
}

// Question 4
int sumV1(int num){
    return (num)*(num+1)/2;
}

int sumV2(int num){
    int sum = 0;
    for(int i = 0;i <= num;i++){
        sum += i;
    }
    return sum;
}


// a class is private (default)
// you need access modifiers like public in it to make its members public elsew we need setters getters (professor will discuss this in
// detail
// for struct the default is public
// No Inheritance in struct. There is inheritance in class (discussed in lecture)

// just a random class
class player{
    public :
        int x,y;
        int speed; // these 3 are the properties of the class

    void move(int xa,int ya){
        x += xa;
        y += ya;
    }// this is a method of the class
};

int multiply(int* arr_factorial_num,int arr_size,int multiplicant){
    int carry = 0;// Initializing the carry
    for (int i = 0;i<arr_size;i++){
        int temp = multiplicant*arr_factorial_num[i] + carry;
        carry = temp/10;
        arr_factorial_num[i] = temp%10;
        cout<<" i is "<<i << " and "<<temp<<endl;
    }
   while (carry)
    {
        arr_factorial_num[arr_size] = carry%10;
        carry = carry/10;
        arr_size++;
    }// while there is carry keep adding it to the array
    return arr_size;
}// multiply()

// Question number 1 (To calculate factorial of large numbers!)
void factorial_of_large_num(int n){
    int max_size = 500; // this is the maximun digits that factorial of a number can have
    int factorial_num[max_size]; // make an array of the maximum number of elements assigned first to store the answer
    factorial_num[0] = 1; // initialize the value. factorial of 0 is 1
    int arr_size = 1; // the array size is one right now
    
    for(int i = 2;i <= n;i++){
        arr_size = multiply(factorial_num,arr_size,i); // we'll do elementary school type multiplication to fill the array
    }
    
    for(int i = arr_size-1;i>=0;i--){
        cout<<factorial_num[i];
    }//printing out the answer. Array is roatated,i.e, the least significant digit is at the right most hand.
}// factorial_of_large_num()

int main(){
    // Question 1
    int n1 = 4;
    int n2 = 12; // This is the maximum that we can compute using unsigned int
    int n3 = -1; // edge case
    int n4 = 0; // edge cases

    unsigned int temp = print_iterative_factorial(n1);
    if(temp == -1){
        cout<<"Factorial of a negative number not valid (complex no)"<<endl;
    }else{
        cout<<"Factorial of "<<n1<<" is "<<temp<<endl;
    }
    temp = print_iterative_factorial(n2);
    if(temp == -1){
        cout<<"Factorial of a negative number not valid (complex no)"<<endl;
    }else{
        cout<<"Factorial of "<<n2<<" is "<<temp<<endl;
    }
    temp = print_iterative_factorial(n3);
    if(temp == -1){
        cout<<"Factorial of a negative number not valid (complex no)"<<endl;
    }else{
        cout<<"Factorial of "<<n3<<" is "<<temp<<endl;
    }
    temp = print_iterative_factorial(n4);
    if(temp == -1){
        cout<<"Factorial of a negative number not valid (complex no)"<<endl;
    }else{
        cout<<"Factorial of "<<n4<<" is "<<temp<<endl;
    }
    
    // This is a way to calculate factorial of large numbers.
    cout<<"ANSWER FOR LARGE NUMBER FACTORIAL IS"<<endl;
    factorial_of_large_num(5);
    cout<<endl;
    
    // Question 2
    // AM = (a + b + c + d + e) / 5
    // GM = (abcde) ^ (1/5)
    // HM =  1 / ((1/a + 1/b + 1/c + 1/d + 1/e) / 5)
    // For our case --> 2/(1/a+1/b)
    
    double a = 7;
    double b = 3;

    cout<<"AM of "<<a<<" and "<<b<< " is "<<AM(a,b)<<endl; // AM
    if(GM(a,b) != -1){
        cout<<"GM of "<<a<<" and "<<b<< " is "<<GM(a,b)<<endl;
    }// GM
    if(HM(a,b) != -1){
        cout<<"HM of "<<a<<" and "<<b<< " is "<<HM(a,b)<<endl;
    } // HM
    
    //Question 3
    double t1=2.0, t2=5, t3=3.1;
//    double t1=1, t2=-5, t3=-9; // answer for this is 𝑥1=6.40512 𝑥2=−1.40512
    double ans_arr[2];
    double ans_p1,ans_p2;
    
    // WAY 1 USING STRUCT
    struct roots q3_answer = roots_of_equation (t1,t2,t3);
    
    // WAY 2 USING PASS BY REFERENCE (passing the adress of the variables in which you want to store the values)
    pass_by_reference(t1,t2,t3,&ans_p1,&ans_p2); // I am passing the address of 2 variables in which I want the answer in
    
    // WAY 3 using array
    find_roots_two(t1,t2,t3,ans_arr);// passing the array and calculating the roots
    
    // Answer for Pass By Reference implementation
    cout<<"PASS BY REFERENCE ANS, root 1 = "<<ans_p1<<" and root 2 is "<<ans_p2<<endl;
    // Answer for Array way of implementation
    cout<<"ROOTS USING ARRAY are root1 =  "<<ans_arr[0]<< " and root 2 = " << ans_arr[1]<<endl;
    // Answer for struct implementation
    if(q3_answer.error_bit != 1){
        cout<<"first root is "<<q3_answer.a<<" and second rot is "<<q3_answer.b<<endl;
    }else{
        cout<< "IMAGINARY ROOTS"<<endl;
    }
    
//    cout<<sqrt(-2)<<" TRY THIS IF YOU WANT TO "<<endl;
    
    // Question 4
    cout<<"V1 "<<sumV1(10)<<endl;
    cout<<"V2 "<<sumV2(10)<<endl;
    
    return 0;
}// main()
 

