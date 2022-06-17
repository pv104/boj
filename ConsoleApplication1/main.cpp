#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <math.h>
using namespace std;
#define CMD_INIT 1
#define CMD_BUY 2
#define CMD_SELL 3
#define CMD_CANCEL 4
#define CMD_BEST_PROFIT 5
#define NUMMAX 200005
#define STOCKMAX 6
#define ARRAYMAX 4
#define NUM 0
#define STOCK 1
#define QUANTITY 2
#define PRICE 3
#define INF 987654321
int buyArray[STOCKMAX][NUMMAX][ARRAYMAX];
int sellArray[STOCKMAX][NUMMAX][ARRAYMAX];
vector <vector<int>> profitArray;
vector <vector<int>> segTree;
pair <int, int> min_Buy, min_Sell;
int maxNumber;
extern void init();
extern int buy(int mNumber, int mStock, int mQuantity, int mPrice);
extern int sell(int mNumber, int mStock, int mQuantity, int mPrice);
extern void cancel(int mNumber);
extern int bestProfit(int mStock);
extern pair<int,int> findMinBuyprice(int mStock,int mPrice);
extern pair<int,int> findMinSellPrice(int mStock,int mPrice);
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

static bool run()
{
    int numQuery;

    int mNumber, mStock, mQuantity, mPrice;

    int userAns, ans;

    bool isCorrect = false;

    scanf("%d", &numQuery);

    for (int i = 0; i < numQuery; ++i)
    {
        //cout << i << " 번째 쿼리 ";
        int cmd;
        scanf("%d", &cmd);
        switch (cmd)
        {
        case CMD_INIT:
            init();
            isCorrect = true;
            break;
        case CMD_BUY:
            scanf("%d %d %d %d", &mNumber, &mStock, &mQuantity, &mPrice);
            userAns = buy(mNumber, mStock, mQuantity, mPrice);
            scanf("%d", &ans);
            if (userAns != ans)
            {
              //  cout << " 틀린 답 : buy, " << userAns << " 맞는 답 : " << ans << "\n";
                isCorrect = false;
            }
            break;
        case CMD_SELL:
            scanf("%d %d %d %d", &mNumber, &mStock, &mQuantity, &mPrice);
            userAns = sell(mNumber, mStock, mQuantity, mPrice);
            scanf("%d", &ans);
            if (userAns != ans)
            {
                //cout << " 틀린 답 : sell, " << userAns << " 맞는 답 : " << ans << "\n";
                isCorrect = false;
            }
            break;
        case CMD_CANCEL:
            scanf("%d", &mNumber);
            cancel(mNumber);
            break;
        case CMD_BEST_PROFIT:
            scanf("%d", &mStock);
            userAns = bestProfit(mStock);
            scanf("%d", &ans);
            if (userAns != ans)
            {
               // cout << " 틀린 답 : BESTPROFIT, " << userAns << " 맞는 답 : " << ans << "\n";
                isCorrect = false;
            }
            break;
        default:
            isCorrect = false;
            break;
        }
    }

    return isCorrect;
}
pair<int, int> findMinBuyPrice(int mStock,int mNumber)
{
    min_Buy.second = -1;
    for (int i = 1; i <= mNumber; i++)
    {
        if (buyArray[mStock][i][PRICE] != INF && (buyArray[mStock][i][PRICE] != 0) && (min_Buy.second < buyArray[mStock][i][PRICE]))
        {
            min_Buy.first = i;
            min_Buy.second = buyArray[mStock][i][PRICE];
          
        }

    }

    return min_Buy;
}
pair<int, int> findMinSellPrice(int mStock,int mNumber)
{
    min_Sell.second = INF;
    for (int i = 1; i <= mNumber; i++)
    {
        if ((sellArray[mStock][i][PRICE] != INF) && (sellArray[mStock][i][PRICE] != 0) && (sellArray[mStock][i][PRICE] < min_Sell.second))
        {
            min_Sell.first = i;
            min_Sell.second = sellArray[mStock][i][PRICE];
        }

    }

    return min_Sell;
}
int makeSegTree(int Node, int S, int E,int mStock)
{
    if (S == E) return segTree[mStock][Node] = profitArray[mStock][S];
    int M = (S + E) / 2;
    int Left = makeSegTree(Node * 2, S, M, mStock);
    int Right = makeSegTree(Node * 2 + 1, M + 1, E, mStock);
    segTree[mStock][Node] = Left + Right;
    return segTree[mStock][Node];
}

void segInit(int mStock)
{
    int treeHeight = (int)ceil(log2(profitArray[mStock].size()));
    int treeSize = (1 << (treeHeight + 1));
    segTree.resize(treeSize);
    makeSegTree(1, 0, profitArray[mStock].size() - 1,mStock);
}
void init()
{
    for (int i = 0; i < STOCKMAX; i++)
    {
        for (int j = 0; j < maxNumber; j++)
        {
            for (int k = 0; k < ARRAYMAX; k++)
            {
                buyArray[i][j][k] = 0;
                sellArray[i][j][k] = 0;
            }
        }
    }
    maxNumber = 0;
    profitArray.clear();
    vector <int> initVector;
    for (int i = 0; i < STOCKMAX; i++)
    {
        profitArray.push_back(initVector);
        segTree.push_back(initVector);
    }
}
int buy(int mNumber, int mStock, int mQuantity, int mPrice)
{
    while (mQuantity != 0)
    {
        min_Sell = findMinSellPrice(mStock,mNumber);
        if (min_Sell.second == INF || min_Sell.second == 0) break; // 값이 없음
        if (min_Sell.second > mPrice) // 살게 없음
            break;
        if (sellArray[mStock][min_Sell.first][QUANTITY] < mQuantity) // 살게 더 많은 경우
        {
            mQuantity -= sellArray[mStock][min_Sell.first][QUANTITY];
            sellArray[mStock][min_Sell.first][QUANTITY] = 0;
            sellArray[mStock][min_Sell.first][PRICE] = INF;
            
        }
        else if (sellArray[mStock][min_Sell.first][QUANTITY] > mQuantity) // 더 적은 경우
        {
            sellArray[mStock][min_Sell.first][QUANTITY] -= mQuantity;
            mQuantity = 0;
        }
        else // 같은 경우
        {
            sellArray[mStock][min_Sell.first][QUANTITY] = 0;
            mQuantity = 0;
            sellArray[mStock][min_Sell.first][PRICE] = INF;
        }/*
        cout << "min_Sell의 판매가격 : " << min_Sell.second << " buyArray[mStock][min_Sell.first][PRICE]의 가격 : " << buyArray[mStock][min_Sell.first][PRICE] << "\n";*/
        profitArray[mStock].push_back(min_Sell.second);
    }
    buyArray[mStock][mNumber][NUM] = mNumber;
    buyArray[mStock][mNumber][STOCK] = mStock;
    buyArray[mStock][mNumber][QUANTITY] = mQuantity;
    if (mQuantity != 0) // 미체결 수량이 있는 경우
    {
        buyArray[mStock][mNumber][PRICE] = mPrice;
    }
    maxNumber = mNumber;
   /* cout << "buy_mQuantity : " << mQuantity << "\n";
   */ return mQuantity;
}
int sell(int mNumber, int mStock, int mQuantity, int mPrice)
{

    while (mQuantity != 0)
    {
        min_Buy = findMinBuyPrice(mStock,mNumber);
        if (min_Buy.second == 0 || min_Buy.second == INF) break;
        if (min_Buy.second < mPrice) // 팔게 없음
            break;
        if (buyArray[mStock][min_Buy.first][QUANTITY] < mQuantity) // 팔게 더 많은 경우
        {
            mQuantity -= buyArray[mStock][min_Buy.first][QUANTITY];
            buyArray[mStock][min_Buy.first][QUANTITY] = 0;
            buyArray[mStock][min_Buy.first][PRICE] = INF;

        }
        else if (buyArray[mStock][min_Buy.first][QUANTITY] > mQuantity) // 더 적은 경우
        {
            buyArray[mStock][min_Buy.first][QUANTITY] -= mQuantity;
            mQuantity = 0;
        }
        else // 같은 경우
        {
            buyArray[mStock][min_Buy.first][QUANTITY] = 0;
            mQuantity = 0;
            buyArray[mStock][min_Buy.first][PRICE] = INF;
        }/*
        cout << "min_Buy의 판매가격 : " << min_Buy.second << " buyArray[mStock][min_Buy.first][PRICE]의 가격 : " << buyArray[mStock][min_Buy.first][PRICE] << "\n";*/
        profitArray[mStock].push_back(min_Buy.second); // min_Buy보다 싸게 파는 사람이 있으면 싸게 사야하니까 min_Buy.second가 아니라 mPrice임
    }
    sellArray[mStock][mNumber][NUM] = mNumber;
    sellArray[mStock][mNumber][STOCK] = mStock;
    sellArray[mStock][mNumber][QUANTITY] = mQuantity;
    if (mQuantity != 0) // 미체결 수량이 있는 경우
    {
        sellArray[mStock][mNumber][PRICE] = mPrice;
    }
    maxNumber = mNumber;
    /*
    cout << "sell_mQuantity : " << mQuantity << "\n";*/
    return mQuantity;
}
void cancel(int mNumber)
{
    for (int i = 1; i < STOCKMAX; i++)
    {
        for (int j = 0; j < ARRAYMAX; j++)
        {
            buyArray[i][mNumber][j] = INF;
            sellArray[i][mNumber][j] = INF;
        }
    }

}
int bestProfit(int mStock)
{
    int maxProfit = 0;
    for (int i = 1; i < profitArray[mStock].size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (maxProfit < (profitArray[mStock][i] - profitArray[mStock][j]))
                maxProfit = (profitArray[mStock][i] - profitArray[mStock][j]);
        }
    }

   
    /*cout << "maxprofit : " << maxProfit << "\n";*/
    return maxProfit;
}
int main()
{
    setbuf(stdout, NULL);
    freopen("sample_input.txt", "r", stdin);

    int T, MARK;
    scanf("%d %d", &T, &MARK);
    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }

    return 0;
}