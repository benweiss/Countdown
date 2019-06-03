//
//  main.cpp
//  Countdown
//
//  Created by Ben Weiss on 5/31/19.
//  Copyright © 2019 Iter9 LLC. All rights reserved.
//

#include <iostream>

struct Hand {
  uint8_t v[6];
  uint8_t weight;
  uint8_t pad;  // because I'm OCD
};

// Enumerates all possible 6-card hands with 0 large cards, returns number of unique hands
int Enumerate0(Hand* hands_, int* weight_sum) {
  Hand* hands = hands_;
  int sum = 0;
  
  // 6 unique values
  for (int v0 = 1; v0 <= 5; v0++) {
    for (int v1 = v0 + 1; v1 <= 6; v1++) {
      for (int v2 = v1 + 1; v2 <= 7; v2++) {
        for (int v3 = v2 + 1; v3 <= 8; v3++) {
          for (int v4 = v3 + 1; v4 <= 9; v4++) {
            for (int v5 = v4 + 1; v5 <= 10; v5++) {
              hands->v[0] = v0;
              hands->v[1] = v1;
              hands->v[2] = v2;
              hands->v[3] = v3;
              hands->v[4] = v4;
              hands->v[5] = v5;
              hands->weight = 64;
              
              sum += 64;
              hands++;
            }
          }
        }
      }
    }
  }
  
  // 5 unique values (5 ways to pick doubled element)
  for (int v0 = 1; v0 <= 6; v0++) {
    for (int v1 = v0 + 1; v1 <= 7; v1++) {
      for (int v2 = v1 + 1; v2 <= 8; v2++) {
        for (int v3 = v2 + 1; v3 <= 9; v3++) {
          for (int v4 = v3 + 1; v4 <= 10; v4++) {
            
            for (int ind = 0; ind < 5; ind++) {
              hands[ind].v[0] = v0;
              hands[ind].v[1] = v1;
              hands[ind].v[2] = v2;
              hands[ind].v[3] = v3;
              hands[ind].v[4] = v4;
              hands[ind].weight = 16;
              sum += 16;
            }
            
            hands[0].v[5] = v0;
            hands[1].v[5] = v1;
            hands[2].v[5] = v2;
            hands[3].v[5] = v3;
            hands[4].v[5] = v4;
            
            hands += 5;
          }
        }
      }
    }
  }
  
  // 4 unique values (6 ways to pick doubled elements)
  for (int v0 = 1; v0 <= 7; v0++) {
    for (int v1 = v0 + 1; v1 <= 8; v1++) {
      for (int v2 = v1 + 1; v2 <= 9; v2++) {
        for (int v3 = v2 + 1; v3 <= 10; v3++) {
          
          for (int ind = 0; ind < 6; ind++) {
            hands[ind].v[0] = v0;
            hands[ind].v[1] = v1;
            hands[ind].v[2] = v2;
            hands[ind].v[3] = v3;
            hands[ind].weight = 4;
            sum += 4;
          }
          
          hands[0].v[4] = v0;  hands[0].v[5] = v1;
          hands[1].v[4] = v0;  hands[1].v[5] = v2;
          hands[2].v[4] = v0;  hands[2].v[5] = v3;
          hands[3].v[4] = v1;  hands[3].v[5] = v2;
          hands[4].v[4] = v1;  hands[4].v[5] = v3;
          hands[5].v[4] = v2;  hands[5].v[5] = v3;
          
          hands += 6;
        }
      }
    }
  }
  
  // 3 unique values (all elements doubled)
  for (int v0 = 1; v0 <= 8; v0++) {
    for (int v1 = v0 + 1; v1 <= 9; v1++) {
      for (int v2 = v1 + 1; v2 <= 10; v2++) {
        hands->v[0] = v0;
        hands->v[1] = v0;
        hands->v[2] = v1;
        hands->v[3] = v1;
        hands->v[4] = v2;
        hands->v[5] = v2;
        hands->weight = 1;
        sum++;
        hands++;
      }
    }
  }
  
  *weight_sum = sum;
  return (int)(hands - hands_);  // implicit count of # of hands
}

// Enumerates all possible 6-card hands with 1 large card, returns number of unique hands
int Enumerate1(Hand* hands_, int* weight_sum) {
  Hand* hands = hands_;
  int sum = 0;
  
  // 5 unique small values
  for (int v0 = 1; v0 <= 6; v0++) {
    for (int v1 = v0 + 1; v1 <= 7; v1++) {
      for (int v2 = v1 + 1; v2 <= 8; v2++) {
        for (int v3 = v2 + 1; v3 <= 9; v3++) {
          for (int v4 = v3 + 1; v4 <= 10; v4++) {
            hands->v[0] = v0;
            hands->v[1] = v1;
            hands->v[2] = v2;
            hands->v[3] = v3;
            hands->v[4] = v4;
            hands->weight = 32;
            
            sum += 32;
            hands++;
          }
        }
      }
    }
  }
  
  // 4 unique small values (4 ways to pick doubled element)
  for (int v0 = 1; v0 <= 7; v0++) {
    for (int v1 = v0 + 1; v1 <= 8; v1++) {
      for (int v2 = v1 + 1; v2 <= 9; v2++) {
        for (int v3 = v2 + 1; v3 <= 10; v3++) {
          
          for (int ind = 0; ind < 4; ind++) {
            hands[ind].v[0] = v0;
            hands[ind].v[1] = v1;
            hands[ind].v[2] = v2;
            hands[ind].v[3] = v3;
            hands[ind].weight = 8;
            sum += 8;
          }
          
          hands[0].v[4] = v0;
          hands[1].v[4] = v1;
          hands[2].v[4] = v2;
          hands[3].v[4] = v3;
          
          hands += 4;
        }
      }
    }
  }
  
  // 3 unique small values (3 ways to pick two doubled elements)
  for (int v0 = 1; v0 <= 8; v0++) {
    for (int v1 = v0 + 1; v1 <= 9; v1++) {
      for (int v2 = v1 + 1; v2 <= 10; v2++) {
        for (int ind = 0; ind < 3; ind++) {
          hands[ind].v[0] = v0;
          hands[ind].v[1] = v1;
          hands[ind].v[2] = v2;
          hands[ind].weight = 2;
          sum += 2;
        }
        
        hands[0].v[3] = v0;  hands[0].v[4] = v1;
        hands[1].v[3] = v0;  hands[1].v[4] = v2;
        hands[2].v[3] = v1;  hands[2].v[4] = v2;
        
        hands += 3;
      }
    }
  }
  
  int num_hands = (int)(hands - hands_);  // implicit count of # of hands
  
  hands = hands_;  // reset pointer
  
  // Duplicate each hand 4 times, to account for different large cards
  for (int ct = 0; ct < num_hands; ct++) {
    hands[num_hands * 1] = hands[0];
    hands[num_hands * 2] = hands[0];
    hands[num_hands * 3] = hands[0];
    
    hands[num_hands * 0].v[5] = 25;
    hands[num_hands * 1].v[5] = 50;
    hands[num_hands * 2].v[5] = 75;
    hands[num_hands * 3].v[5] = 100;
    
    hands++;
  }
  
  *weight_sum = sum * 4;
  return num_hands * 4;
}

// Enumerates all possible 6-card hands with 2 large cards, returns number of unique hands
int Enumerate2(Hand* hands_, int* weight_sum) {
  Hand* hands = hands_;
  int sum = 0;
  
  // 4 unique small values
  for (int v0 = 1; v0 <= 7; v0++) {
    for (int v1 = v0 + 1; v1 <= 8; v1++) {
      for (int v2 = v1 + 1; v2 <= 9; v2++) {
        for (int v3 = v2 + 1; v3 <= 10; v3++) {
          hands->v[0] = v0;
          hands->v[1] = v1;
          hands->v[2] = v2;
          hands->v[3] = v3;
          hands->weight = 16;
          
          sum += 16;
          hands++;
        }
      }
    }
  }
  
  // 3 unique small values (3 ways to pick doubled element)
  for (int v0 = 1; v0 <= 8; v0++) {
    for (int v1 = v0 + 1; v1 <= 9; v1++) {
      for (int v2 = v1 + 1; v2 <= 10; v2++) {
        for (int ind = 0; ind < 3; ind++) {
          hands[ind].v[0] = v0;
          hands[ind].v[1] = v1;
          hands[ind].v[2] = v2;
          hands[ind].weight = 4;
          sum += 4;
        }
        
        hands[0].v[3] = v0;  hands[0].v[4] = v1;
        hands[1].v[3] = v0;  hands[1].v[4] = v2;
        hands[2].v[3] = v1;  hands[2].v[4] = v2;
        
        hands += 3;
      }
    }
  }
  
  // 2 unique small values (both doubled)
  for (int v0 = 1; v0 <= 9; v0++) {
    for (int v1 = v0 + 1; v1 <= 10; v1++) {
      hands[0].v[0] = v0;
      hands[0].v[1] = v0;
      hands[0].v[2] = v1;
      hands[0].v[3] = v1;
      hands[0].weight = 1;
      sum++;
      hands++;
    }
  }
  
  int num_hands = (int)(hands - hands_);  // implicit count of # of hands
  
  hands = hands_;  // reset pointer
  
  // Duplicates each hand 6 times, to account for different large cards
  for (int ct = 0; ct < num_hands; ct++) {
    hands[num_hands * 1] = hands[0];
    hands[num_hands * 2] = hands[0];
    hands[num_hands * 3] = hands[0];
    hands[num_hands * 4] = hands[0];
    hands[num_hands * 5] = hands[0];
    
    hands[num_hands * 0].v[4] = 25;  hands[num_hands * 0].v[5] = 50;
    hands[num_hands * 1].v[4] = 25;  hands[num_hands * 1].v[5] = 75;
    hands[num_hands * 2].v[4] = 25;  hands[num_hands * 2].v[5] = 100;
    hands[num_hands * 3].v[4] = 50;  hands[num_hands * 3].v[5] = 75;
    hands[num_hands * 4].v[4] = 50;  hands[num_hands * 4].v[5] = 100;
    hands[num_hands * 5].v[4] = 75;  hands[num_hands * 5].v[5] = 100;
    
    hands++;
  }
  
  *weight_sum = sum * 6;
  return num_hands * 6;
}

// Enumerates all possible 6-card hands with 3 large cards, returns number of unique hands
int Enumerate3(Hand* hands_, int* weight_sum) {
  Hand* hands = hands_;
  int sum = 0;
  
  // 3 unique small values
  for (int v0 = 1; v0 <= 8; v0++) {
    for (int v1 = v0 + 1; v1 <= 9; v1++) {
      for (int v2 = v1 + 1; v2 <= 10; v2++) {
        hands->v[0] = v0;
        hands->v[1] = v1;
        hands->v[2] = v2;
        hands->weight = 8;
        sum += 8;
        hands++;
      }
    }
  }
  
  // 2 unique small values (2 ways to pick doubled element)
  for (int v0 = 1; v0 <= 9; v0++) {
    for (int v1 = v0 + 1; v1 <= 10; v1++) {
      hands[0].v[0] = v0;
      hands[0].v[1] = v1;
      hands[0].v[2] = v0;
      hands[0].weight = 2; sum += 2;
      
      hands[1].v[0] = v0;
      hands[1].v[1] = v1;
      hands[1].v[2] = v1;
      hands[1].weight = 2; sum += 2;
      
      hands += 2;
    }
  }
  
  int num_hands = (int)(hands - hands_);  // implicit count of # of hands
  
  hands = hands_;  // reset pointer
  
  // Duplicates each hand 4 times, to account for different large cards
  for (int ct = 0; ct < num_hands; ct++) {
    hands[num_hands * 1] = hands[0];
    hands[num_hands * 2] = hands[0];
    hands[num_hands * 3] = hands[0];
    
    hands[num_hands * 0].v[3] = 25;
    hands[num_hands * 0].v[4] = 50;
    hands[num_hands * 0].v[5] = 75;
    
    hands[num_hands * 1].v[3] = 25;
    hands[num_hands * 1].v[4] = 50;
    hands[num_hands * 1].v[5] = 100;
    
    hands[num_hands * 2].v[3] = 25;
    hands[num_hands * 2].v[4] = 75;
    hands[num_hands * 2].v[5] = 100;
    
    hands[num_hands * 3].v[3] = 50;
    hands[num_hands * 3].v[4] = 75;
    hands[num_hands * 3].v[5] = 100;
    
    hands++;
  }
  
  *weight_sum = sum * 4;
  return num_hands * 4;
}

// Enumerates all possible 6-card hands with 4 large cards, returns number of unique hands
int Enumerate4(Hand* hands_, int* weight_sum) {
  Hand* hands = hands_;
  int sum = 0;
  
  // 2 unique small values
  for (int v0 = 1; v0 <= 9; v0++) {
    for (int v1 = v0 + 1; v1 <= 10; v1++) {
      hands->v[0] = v0;
      hands->v[1] = v1;
      hands->v[2] = 25;
      hands->v[3] = 50;
      hands->v[4] = 75;
      hands->v[5] = 100;
      hands->weight = 4;
      sum += 4;
      hands++;
    }
  }
  
  // 1 unique small value
  for (int v0 = 1; v0 <= 10; v0++) {
    hands[0].v[0] = v0;
    hands[0].v[1] = v0;
    hands->v[2] = 25;
    hands->v[3] = 50;
    hands->v[4] = 75;
    hands->v[5] = 100;
    hands[0].weight = 1;
    sum++;
    hands++;
  }
  
  *weight_sum = sum;
  return (int)(hands - hands_);  // implicit count of # of hands
}


// For the given hand of 'ct' cards, writes '1' to each reachable mask element,
// then applies basic operators to "shorten" hand and recurses.
// For individual tests, you can set breakpoints at the various "target reached"
// points and crawl through the stack to see how it was reached.
static void TestHand(int* hand, int count, uint8_t* mask, int* target) {
  if (count < 2) return;
  
  // Loops through all pairs of numbers
  for (int l = 0; l < count - 1; l++) {
    for (int r = l + 1; r < count; r++) {
      int lv = hand[l];
      int rv = hand[r];
      
      hand[r] = hand[count - 1];
      
      // Addition
      int v = lv + rv;
      if (v >= 100 && v <= 999) { mask[v] = 1; }
      if (target && v == *target) {
        // printf("target reached");
      }
      hand[l] = v;
      TestHand(hand, count - 1, mask, target);
      
      // Subtraction
      v = lv > rv ? lv - rv : rv - lv;
      if (v > 0) {
        if (v >= 100 && v <= 999) { mask[v] = 1; }
        if (target && v == *target) {
          // printf("target reached");
        }
        hand[l] = v;
        TestHand(hand, count - 1, mask, target);
      }
      
      // Only applies multiplication and division in nontrivial cases
      if (lv > 1 && rv > 1) {
        // Multiplication
        v = lv * rv;
        if (v >= 100 && v <= 999) { mask[v] = 1; }
        if (target && v == *target) {
          // printf("target reached");
        }
        hand[l] = v;
        TestHand(hand, count - 1, mask, target);
        
        // Division (applies only if exact)
        v = lv > rv ? lv / rv : rv / lv;
        if (lv * v == rv || rv * v == lv) {
          if (v >= 100 && v <= 999) { mask[v] = 1; }
          if (target && v == *target) {
            // printf("target reached");
          }
          hand[l] = v;
          TestHand(hand, count - 1, mask, target);
        }
      }
      
      // restore hand
      hand[l] = lv;
      hand[r] = rv;
    }
  }
}

// Iterates through a list of hands, testing each one to see which target values it can reach.
// Generates a histogram of how often each target value is reached, and prints statistics
// about the percentage of solvable hands, and most- and least-reachable target values.
void TestHands(Hand* hands, int num_hands, int weight_sum) {
  int hist[1000] = { 0 };  // whether the 3-digit number can be made (first 100 elements unused)
  
  for (int trial = 0; trial < num_hands; trial++) {
    uint8_t mask[1000] = { 0 };
    
    int hand[6] = { hands[trial].v[0],
      hands[trial].v[1],
      hands[trial].v[2],
      hands[trial].v[3],
      hands[trial].v[4],
      hands[trial].v[5]
    };
    
    TestHand(hand, 6, mask, NULL);  // test hand against all 900 possible 3-digit numbers
    
    /*  This code finds hands corresponding that can't reach a few values reachable by any other hand.
     int test[] = { 109, 113, 116, 120, 121, 129, 130, 141, 176, 201, 225, 275 };
     
     for (int ind = 0; ind < sizeof(test) / sizeof(int); ind++) {
     if (mask[test[ind]] == 0) {
     printf("Hand %i, %i, %i, %i, %i, %i can't make %i\n", hand[0], hand[1], hand[2], hand[3], hand[4], hand[5], test[ind]);
     }
     }
     */
    
    for (int ind = 100; ind <= 999; ind++) {
      hist[ind] += mask[ind] * hands[trial].weight;
    }
  }
  
  int ct = 0;
  for (int ind = 100; ind <= 999; ind++) {
    ct += hist[ind];
  }
  
  float pct = float(ct) / (weight_sum * 900);
  
  printf("Targets reachable %f%% of the time\n", pct * 100);
  
  // Ranks the top and bottom 'kRanked' targets by solvability
  constexpr int kRanked = 50;
  
  int best_ind[kRanked];
  int best_ct[kRanked];
  int worst_ind[kRanked];
  int worst_ct[kRanked];
  
  // enumerate best targets
  for (int rank = 0; rank < kRanked; rank++) {
    int highest_ct = -1;
    int highest_ind = -1;
    for (int ind = 100; ind <= 999; ind++) {
      if (hist[ind] > highest_ct) {
        highest_ind = ind;
        highest_ct = hist[ind];
      }
    }
    best_ind[rank] = highest_ind;
    best_ct[rank] = highest_ct;
    
    hist[highest_ind] = -1;  // exclude from next pass
    
    printf("Best target %i = %i, reachable %3.4f%% of the time\n",
           rank + 1, highest_ind, 100 * float(highest_ct) / weight_sum);
  }
  
  // restore histogram
  for (int rank = 0; rank < kRanked; rank++) {
    hist[best_ind[rank]] = best_ct[rank];
  }
  
  // enumerate worst targets
  for (int rank = 0; rank < kRanked; rank++) {
    int lowest_ct = weight_sum + 1;
    int lowest_ind = -1;
    for (int ind = 100; ind <= 999; ind++) {
      if (hist[ind] < lowest_ct) {
        lowest_ind = ind;
        lowest_ct = hist[ind];
      }
    }
    worst_ind[rank] = lowest_ind;
    worst_ct[rank] = lowest_ct;
    
    hist[lowest_ind] = weight_sum + 1;  // exclude from next pass
    
    printf("Worst target %i = %i, reachable %3.4f%% of the time\n",
           rank + 1, lowest_ind, 100 * float(lowest_ct) / weight_sum);
  }
  
  // restore histogram
  for (int rank = 0; rank < kRanked; rank++) {
    hist[worst_ind[rank]] = worst_ct[rank];
  }
}


static void UnitTestExample() {
  
  int hand[6] = { 50, 2, 4, 4, 6, 10 };
  int target = 687;
  
  uint8_t mask[1000] = { 0 };
  
  TestHand(hand, 6, mask, &target);
  
  int ct = 0;
  for (int ind = 100; ind <= 999; ind++) {
    ct += mask[ind];
  }
  
  printf("%i / 900 targets reachable with hand { %i, %i, %i, %i, %i, %i }\n",
         ct, hand[0], hand[1], hand[2], hand[3], hand[4], hand[5]);
}

int main(int argc, const char * argv[]) {
  // Note: # of unique hands with [0..4] large cards = { 2850, 5808, 3690, 840, 55 }
  Hand* hands = (Hand*)malloc(sizeof(Hand) * 5808);
  int weight_sum = 0;
  int num_hands;
  
  num_hands = Enumerate0(hands, &weight_sum);
  printf("Number of hands with 0 large cards = %i, weight sum = %i\n", num_hands, weight_sum);
  TestHands(hands, num_hands, weight_sum);
  
  num_hands = Enumerate1(hands, &weight_sum);
  printf("Number of hands with 1 large cards = %i, weight sum = %i\n", num_hands, weight_sum);
  TestHands(hands, num_hands, weight_sum);
  
  num_hands = Enumerate2(hands, &weight_sum);
  printf("Number of hands with 2 large cards = %i, weight sum = %i\n", num_hands, weight_sum);
  TestHands(hands, num_hands, weight_sum);
  
  num_hands = Enumerate3(hands, &weight_sum);
  printf("Number of hands with 3 large cards = %i, weight sum = %i\n", num_hands, weight_sum);
  TestHands(hands, num_hands, weight_sum);
  
  num_hands = Enumerate4(hands, &weight_sum);
  printf("Number of hands with 4 large cards = %i, weight sum = %i\n", num_hands, weight_sum);
  TestHands(hands, num_hands, weight_sum);
  
  return 0;
}
