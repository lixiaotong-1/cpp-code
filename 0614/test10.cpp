#include <iostream>

extern int shared_num;

void increnum()
{
    static int count = 0;
    ++count;
    std::cout << count << std::endl;
}

int main()
{
    increnum();
    // std::cout << count << "\n";
    return 0;
}