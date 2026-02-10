class Solution
{
public:
    int mySqrt(int x)
    {
        if (x < 2)
            return x;
        long long guess = x; // 首次猜测值

        while (guess * guess > x)
        {
            guess = (guess + x / guess) / 2;
        }
        return (int)guess;
    }
};

int main()
{
    return 0;
}