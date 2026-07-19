//Chess
#include<cstdint>
#include <iostream>
typedef uint64_t U64; //unsigned 64 bit integer(cannot hold negative numberes)
//empty chess board
U64 board = 0x0000000000000000ULL;
 
//White pawn aquirement in the board 
U64 WP =    0x000000000000FF00ULL;
//White castle
U64 WC =    0x0000000000000081ULL;
//White knight 
U64 WN =    0x0000000000000042ULL;   
//White Bishop
U64 WB =    0x0000000000000024ULL;
//White Queen
U64 WQ =    0x0000000000000008ULL;
//White King 
U64 WK =    0x0000000000000010ULL;

//Black pawn aquirement in the board
U64 BP =    0x00FF000000000000ULL;
//Black castle
U64 BC =    0x8100000000000000ULL;
//Black knight 
U64 BN =    0x4200000000000000ULL;   
//Black Bishop
U64 BB =    0x2400000000000000ULL;
//Black Queen
U64 BQ =    0x0800000000000000ULL;
//Black King 
U64 BK =    0x1000000000000000ULL;

//All White 
U64 ALL_WHITE = WP|WC|WN|WB|WQ|WK;
//All Black 
U64 ALL_BLACK = BP|BC|BN|BB|BQ|BK;

U64 OCCUPIED = ALL_WHITE|ALL_BLACK;

U64 EMPTY = ~OCCUPIED;//Empty Squares