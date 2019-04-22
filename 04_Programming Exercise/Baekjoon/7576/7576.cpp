#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

#define TOMATO_RIPING	2
#define TOMATO_RIPE		1
#define TOMATO_RAW		0
#define TOMATO_NONE		-1

#define OUT_OF_RANGE	-1

#define DIR_EAST	1
#define DIR_NORTH	2
#define DIR_WEST	3
#define DIR_SOUTH	4

class TomatoMap
{
	public:
	TomatoMap(int height, int width);
	
	public:
	int GetTomatoState(int row, int col);
	int GetTomatoState(int idx);
	int GetOffsetIdx(int row, int col, int dir);
	int GetOffsetIdx(int idx, int dir);
	
	public:
	void SetTomatoState(int row, int col, int state);
	void SetTomatoState(int idx, int state);
	
	private:
	std::vector<int> tomato_map_;
	int height_, width_;
};

TomatoMap::TomatoMap(int height, int width) : height_(height), width_(width)
{
	tomato_map_.resize(height * width);
}

int TomatoMap::GetTomatoState(int row, int col)
{
	int idx = width_ * row + col;
	return GetTomatoState(idx);
}

int TomatoMap::GetTomatoState(int idx)
{
	return tomato_map_[idx];
}

int TomatoMap::GetOffsetIdx(int row, int col, int dir)
{
	int idx = width_ * row + col;
	
	if (dir == DIR_EAST)
		return (col < width_ - 1 ? idx + 1 : OUT_OF_RANGE);
	else if (dir == DIR_NORTH)
		return (row > 0 ? idx - width_ : OUT_OF_RANGE);
	else if (dir == DIR_WEST)
		return (col > 0 ? idx - 1 : OUT_OF_RANGE);
	else if (dir == DIR_SOUTH)
		return (row < height_ - 1 ? idx + width_ : OUT_OF_RANGE);
}

int TomatoMap::GetOffsetIdx(int idx, int dir)
{
	int row = idx / width_;
	int col = idx % width_;
	return GetOffsetIdx(row, col, dir);
}

void TomatoMap::SetTomatoState(int row, int col, int state)
{
	int idx = width_ * row + col;
	SetTomatoState(idx, state);
}

void TomatoMap::SetTomatoState(int idx, int state)
{
	tomato_map_[idx] = state;
}


int main(void)
{
	freopen("input.txt", "r", stdin);
	
	int height, width, tomatoState;
	int idx, idxOffset;
	int ripeTomatoCnt = 0, rawTomatoCnt = 0, emptyCnt = 0;
	int days = 0, riping = 0, ripe = 0;
	fscanf(stdin, "%d %d", &width, &height);
	TomatoMap tomatoMap(height, width);
	std::queue<int> ripeTomatoes;
	
	// Read the states of tomatoes.
	for (int r = 0; r < height; r++)
	{
		for (int c = 0; c < width; c++)
		{
			fscanf(stdin, "%d", &tomatoState);
			tomatoMap.SetTomatoState(r, c, tomatoState);
			
			// Push to queue if the tomato is ripe.
			if (tomatoState == TOMATO_RIPE)
			{
				idx = r * width + c;
				ripeTomatoes.push(idx);
				++ripeTomatoCnt;
				++ripe;
			}
			else if (tomatoState == TOMATO_RAW)
			{
				++rawTomatoCnt;
			}
			else if (tomatoState == TOMATO_NONE)
			{
				++emptyCnt;
			}
		}
	}
	
	
	// Case: If all tomatoes were already ripe.
	if (rawTomatoCnt == 0)
	{
		fprintf(stdout, "0 \n");
		return 0;
	}
	
	// Case: If some tomatoes are not ripe.
	while (1)
	{
		if (ripeTomatoes.empty())
		{
			--days;
			if (rawTomatoCnt != 0)
			{
				fprintf(stdout, "-1 \n");
				return 0;
			}

			fprintf(stdout, "%d \n", days);
			return 0;
		}
		
		riping = 0;
		for (int i = 0; i < ripe; i++)
		{	
			idx = ripeTomatoes.front();
			ripeTomatoes.pop();

			// Test eastside.
			idxOffset = tomatoMap.GetOffsetIdx(idx, DIR_EAST);
			if (idxOffset != OUT_OF_RANGE && tomatoMap.GetTomatoState(idxOffset) == TOMATO_RAW)
			{
				tomatoMap.SetTomatoState(idxOffset, TOMATO_RIPE);
				ripeTomatoes.push(idxOffset);
				++riping; ++ripeTomatoCnt; --rawTomatoCnt;
			}
			
			// Test northside.
			idxOffset = tomatoMap.GetOffsetIdx(idx, DIR_NORTH);
			if (idxOffset != OUT_OF_RANGE && tomatoMap.GetTomatoState(idxOffset) == TOMATO_RAW)
			{
				tomatoMap.SetTomatoState(idxOffset, TOMATO_RIPE);
				ripeTomatoes.push(idxOffset);
				++riping; ++ripeTomatoCnt; --rawTomatoCnt;
			}
			
			// Test westside.
			idxOffset = tomatoMap.GetOffsetIdx(idx, DIR_WEST);
			if (idxOffset != OUT_OF_RANGE && tomatoMap.GetTomatoState(idxOffset) == TOMATO_RAW)
			{
				tomatoMap.SetTomatoState(idxOffset, TOMATO_RIPE);
				ripeTomatoes.push(idxOffset);
				++riping; ++ripeTomatoCnt; --rawTomatoCnt;
			}
			
			// Test southside.
			idxOffset = tomatoMap.GetOffsetIdx(idx, DIR_SOUTH);
			if (idxOffset != OUT_OF_RANGE && tomatoMap.GetTomatoState(idxOffset) == TOMATO_RAW)
			{
				tomatoMap.SetTomatoState(idxOffset, TOMATO_RIPE);
				ripeTomatoes.push(idxOffset);
				++riping; ++ripeTomatoCnt; --rawTomatoCnt;
			}
		}
		
		ripe = riping;
		++days;
		// fprintf(stdout, "%d \n", days);
	}
}