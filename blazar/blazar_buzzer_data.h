#ifndef _BUZZER_DATA_H_
#define _BUZZER_DATA_H_

#include <stdint.h>

/* Equal temperament notes */
#define C3_NATURAL 131
#define D3_NATURAL 148
#define E3_NATURAL 166
#define F3_NATURAL 175
#define G3_NATURAL 197
#define A3_NATURAL 221
#define B3_NATURAL 248
#define C4_NATURAL 263
#define D4_NATURAL 295
#define E4_NATURAL 331
#define F4_NATURAL 351
#define G4_NATURAL 394
#define A4_NATURAL 442
#define B4_NATURAL 496
#define C5_NATURAL 526

/*!
 * @brief Song data
 *
 * Dimension 1: song. 
 * Dimension 2: the first element(an array of only one element) is the total number of notes while others are notes. 
 * Dimension 3: description of a single note, whose two elements are {frequency, duration}. 
 */
const uint16_t SONG_DATA[][50][2] = {
	{0}, 
	
	// Song 1: major scale
	{{8},
	{526, 500}, //C5
	{590, 500}, //D5
	{662, 500}, 
	{702, 500}, 
	{788, 500}, 
	{702, 500}, 
	{662, 500}, 
	{590, 500}}, 
	
	// Song 2: birthday song
	{{25}, 
	{788, 250}, //G5
	{788, 250}, 
	
	{884, 500}, 
	{788, 500}, 
	{1051, 500}, //C6
	{992, 1000}, 
	{788, 250}, //G5
	{788, 250},
	
	{884, 500}, 
	{788, 500}, 
	{1180, 500}, 
	{1051, 1000}, 
	{788, 250}, //G5
	{788, 250},
	
	{1575, 500}, //G6
	{1324, 500},
	{1051, 500},
	{992, 500},
	{884, 1000},  //Fermata
	{1403, 250},
	{1403, 250},
	
	{1324, 500},
	{1051, 500},
	{1180, 500},
	{1051, 1000}}
};

#endif /* _BUZZER_DATA_H_ */
