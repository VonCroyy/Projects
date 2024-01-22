#include <iostream>
#include <vector>
#include <cstdlib>
#include <thread>

using std::cin;
using std::cout;
using std::endl;
using std::flush;

int main()
{
    std::vector<int> list;

    char user_input{};
    bool flag{false};

    system("cls");

    do
    {
        cout << "P - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "D - Search for duplicates" << endl;
        cout << "C - Clear the list" << endl;
        cout << "E - Duplicate entries (ON/OFF)" << endl;
        cout << "Q - Quit" << endl;
        cout << "\nEnter your choice: " << flush;

        cin >> user_input;

        switch (user_input)
        {
        case 'p':
        case 'P':
            if (list.size() == 0)
            {
                cout << "\n[] - the list is empty\n"
                     << endl;
            }
            else
            {
                cout << "\n[" << flush;

                for (int i = 0; i < static_cast<signed>(list.size()); i++)
                {
                    if (i == static_cast<signed>(list.size()) - 1)
                        cout << list.at(i) << flush;
                    else
                        cout << list.at(i) << " " << flush;
                }

                cout << "]\n"
                     << endl;
            }
            break;
        case 'a':
        case 'A':
        {
            int number{0};
            bool check{false};

            cout << "\nadd an integer: " << flush;
            cin >> number;

            if (flag == true)
            {
                for (int i{0}; i < 1; i++)
                {
                    for (auto element : list)
                    {
                        if (element == number)
                        {
                            cout << "\nNo duplicate numbers allowed - try again\n"
                                 << endl;
                            check = true;
                            break;
                        }
                    }

                    if (check == false)
                    {
                        list.push_back(number);
                        cout << number << " added\n"
                             << endl;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                list.push_back(number);
                cout << number << " added\n"
                     << endl;
            }
            break;
        }
        case 'm':
        case 'M':
        {
            double sum{0};

            if (list.size() != 0)
            {
                for (auto element : list)
                {
                    sum += element;
                }

                sum /= list.size();

                cout << "\nthe mean of the list: " << sum << "\n"
                     << endl;
            }
            else
            {
                cout << "\nUnable to calculate mean - no data\n"
                     << endl;
            }
            break;
        }
        case 's':
        case 'S':
        {
            if (list.size() != 0)
            {
                int min{list.at(0)};

                for (auto element : list)
                {
                    if (element < min)
                    {
                        min = element;
                    }
                }

                cout << "\nThe smallest number is " << min << "\n"
                     << endl;
            }
            else
            {
                cout << "\nUnable to determine the smallest number - list is empty\n"
                     << endl;
            }
            break;
        }
        case 'l':
        case 'L':
        {
            if (list.size() != 0)
            {
                int max{list.at(0)};

                for (auto element : list)
                {
                    if (element > max)
                    {
                        max = element;
                    }
                }

                cout << "\nThe largest number is " << max << "\n"
                     << endl;
            }
            else
            {
                cout << "\nUnable to determine the largest number - list is empty\n"
                     << endl;
            }
            break;
        }
        case 'd':
        case 'D':
        {
            if (list.size() != 0)
            {
                int duplicate{};

                for (int i{0}; i < static_cast<signed>(list.size()); i++)
                {
                    for (int j{0}; j < static_cast<signed>(list.size()); j++)
                    {
                        if (j <= i)
                        {
                            continue;
                        }
                        else if (list.at(i) == list.at(j))
                        {
                            duplicate++;
                        }
                    }
                }

                cout << "\nThere are " << duplicate << " duplicate numbers\n"
                     << endl;
            }
            else
            {
                cout << "\nUnable to determine duplicates - no data\n"
                     << endl;
            }
            break;
        }
        case 'c':
        case 'C':
        {
            list.clear();

            cout << "\nThe list has been cleared\n"
                 << endl;
            break;
        }
        case 'e':
        case 'E':
        {
            if (flag == false)
            {
                cout << "\nDuplicate entries OFF\n"
                     << endl;
                flag = true;
            }
            else
            {
                cout << "\nDuplicate entries ON\n"
                     << endl;
                flag = false;
            }
            break;
        }
        default:
            if (user_input != 'q' && user_input != 'Q')
                cout << "\nUnknown selection, please try again\n"
                     << endl;
        }

        if (user_input != 'Q' && user_input != 'q')
        {
            system("pause");
            system("cls");
        }

    } while (user_input != 'Q' && user_input != 'q');

    cout << "\nGoodbye" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    system("cls");

    return 0;
}