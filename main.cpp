#include <QCoreApplication>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

const int MAX_TOTAL = 150;
const int MAX_A = 4;
const int MAX_B = 3;
const int MAX_C = 10;
const string greet = "Добрый день!";
const string menu = "Внесите, пожалуйста, деньги, а затем выберите одну из следующих опций:";
const string menu1 = "а) Кекс (50 руб.)";
const string menu2 = "б) Печенье (10 руб.)";
const string menu3 = "в) Вафли (30 руб.)";
const string menu4 = "г) Вернуть оставшиеся деньги";
const string choise = "Для выполнения операции выберите соответствующий пункт или напишите название операции";


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    char answer[26];
    cout<<greet<<endl;
    cout<<menu<<endl;
    cout<<menu1<<endl<<menu2<<endl<<menu3<<endl<<menu4<<endl;
    cout<<choise<<endl;
    cout<<"Внесите деньги или выберите операцию"<<endl;
    int i=0;
    int coins1OnHand=0; // Известное количество монет номиналом 1 руб на руках у покупателя
    int coins2OnHand=0;
    int coins5OnHand=0;
    int coins10OnHand=0;
    int balance=0; // Баланс покупателя
    int total=0; // Общее количество денег, внесенных покупателем. Баланс+покупки
    int avalA=MAX_A; //Доступное количество товара А (кексов)
    int avalB=MAX_B;
    int avalC=MAX_C;
    int unknownMoney=MAX_TOTAL; // Количество денег покупателя, в виде монет неизестного номинала
    
    while (1)
    {
        cin>>answer;
        if (!(strcmp(answer, "0")))
            cout<<"Вы не можете внести 0 рублей"<<endl;
        
        else{
        if ((!(strcmp(answer, "а")))||(!(strcmp(answer, "Кекс"))))
        {
            if (balance>=50)
            {
                if (avalA==0)
                {
                    cout<<"К сожалению, кексы кончились"<<endl;
                }else
                {
                    avalA--;
                    cout<<"Вы купили кекс"<<endl;
                    balance-=50;
                    cout<<"Ваш баланс "<<balance<<" руб."<<endl;
                }
            }else
                cout<<"Вы внесли недостаточно денег, чтобы купить кекс"<<endl;
        }
        
        else{
        if ((!(strcmp(answer, "б")))||(!(strcmp(answer, "Печенье"))))
        {
            if (balance>=10)
            {
                if (avalB==0)
                {
                    cout<<"К сожалению, печенье кончилось"<<endl;
                }else
                {
                    avalB--;
                    cout<<"Вы купили печенье"<<endl;
                    balance-=10;
                    cout<<"Ваш баланс "<<balance<<" руб."<<endl;
                }
            }else
                cout<<"Вы внесли недостаточно денег, чтобы купить печенье"<<endl;
        }
        
        else{
        if ((!(strcmp(answer, "в")))||(!(strcmp(answer, "Вафли"))))
        {
            if (balance>=30)
            {
                if (avalC==0)
                {
                    cout<<"К сожалению, вафли кончились"<<endl;
                }else
                {
                    avalC--;
                    cout<<"Вы купили вафли"<<endl;
                    balance-=30;
                    cout<<"Ваш баланс "<<balance<<" руб."<<endl;
                }
            }else
                cout<<"Вы внесли недостаточно денег, чтобы купить вафли"<<endl;
        }
        
        else{
        if ((!(strcmp(answer, "г")))||(!(strcmp(answer, "Вернуть оставшиеся деньги"))))
        {
            if (balance==0)
                cout<<"На вашем балансе нет денег"<<endl;
            else
            {
                int coins=0; // Количество монет данного номинала, возращаемых покупателю
                while (balance>=10)
                {coins++; balance-=10;}
                total-=coins*10;
                coins10OnHand+=coins; // Теперь мы знаем, что у покупаля точно есть coins10OnHand монет номиналом 1 руб
                cout<<"Вы получили "<<coins<<" монет по 10 рублей"<<endl;
                coins=0;
                while (balance>=5)
                {coins++; balance-=5;}
                total-=coins*5;
                coins5OnHand+=coins;
                cout<<"Вы получили "<<coins<<" монет по 5 рублей"<<endl;
                coins=0;
                while (balance>=2)
                {coins++; balance-=2;}
                total-=coins*2;
                coins2OnHand+=coins;
                cout<<"Вы получили "<<coins<<" монет по 2 рубля"<<endl;
                coins1OnHand+=balance;
                total-=balance;
                cout<<"Вы получили "<<balance<<" монет по 1 рублю"<<endl;
                balance=0;
            }
        }
        
        else{
        if (!(atoi(answer)==0)) // Если введено число
        {
            i=atoi(answer);
            switch (i)
            {
                case 1:
                    {
                        if ((total+i)>MAX_TOTAL)
                        {
                            cout<<"Вы не можете внести 1 руб. У вас кончились деньги"<<endl;
                            break;
                        }
                        if (coins1OnHand==0) // Если мы не знали, что у покупателя еще были монеты номиналом 1 руб
                        {
                            if (unknownMoney<i) // Если у него больше нет "неизвестных" денег, то у него нет такой монеты
                            {
                                cout<<"Вы не можете внести 1 руб. У вас нет монет такого номинала"<<endl;
                                break;
                            }
                            unknownMoney-=i; // Если у него были "неизвестные" деньги, их стало меньше
                        }else
                        {coins1OnHand--;} // Известное количество монет номиналом 1 руб уменьшилось
                        balance+=i;
                        total+=i;
                        break;
                    }
                 case 2:
                     {
                if ((total+i)>MAX_TOTAL)
                {
                    cout<<"Вы не можете внести 2 руб. У вас кончились деньги"<<endl;
                    break;
                }
                if (coins2OnHand==0)
                {
                    if (unknownMoney<i)
                    {
                        cout<<"Вы не можете внести 2 руб. У вас нет монет такого номинала"<<endl;
                        break;
                    }
                    unknownMoney-=i;
                }else
                    {coins2OnHand--;}
                        balance+=i;
                        total+=i;
                        break;
                     }
            case 5:
                {
                if ((total+i)>MAX_TOTAL)
                {
                    cout<<"Вы не можете внести 5 руб. У вас кончились деньги"<<endl;
                    break;
                }
                if (coins5OnHand==0)
                {
                    if (unknownMoney<i)
                    {
                        cout<<"Вы не можете внести 5 руб. У вас нет монет такого номинала"<<endl;
                        break;
                    }
                    unknownMoney-=i;
                }else
                    {coins5OnHand--;}
                    balance+=i;
                    total+=i;
                    break;
                }
            case 10:
                {
                if ((total+i)>MAX_TOTAL)
                {
                    cout<<"Вы не можете внести 10 руб. У вас кончились деньги"<<endl;
                    break;
                }
                if (coins10OnHand==0)
                {
                    if (unknownMoney<i)
                    {
                        cout<<"Вы не можете внести 10 руб. У вас нет монет такого номинала"<<endl;
                        break;
                    }
                    unknownMoney-=i;
                }else
                    {coins10OnHand--;}
                    balance+=i;
                    total+=i;
                    break;
                }
            default:
                cout<<"Я не принимаю монеты такого номинала"<<endl;

            }
            cout<<"Ваш баланс "<<balance<<" руб."<<endl;
        }else
            cout<<"Я вас не понимаю"<<endl;
        }}}}}
    }

    return a.exec();
}
