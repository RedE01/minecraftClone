#pragma once
#include "Block.h"
#include <vector>
#include <array>
#include "Math.h"

#define CHUNK_WIDTH 16
#define CHUNK_HEIGHT 128
#define CHUNK_SEGMENT_HEIGHT CHUNK_WIDTH
#define CHUNK_SEGMENTS CHUNK_HEIGHT / CHUNK_SEGMENT_HEIGHT

enum CubeSide {
	Front, Back, Left, Right, Top, Down
};

class CubeModelData {
public:
	static std::array<float, 48> getData(CubeSide cubeSide, Vector3 position, float textureX, float textureY) {
		if(cubeSide == CubeSide::Front) {
			return {
				0.0f  + position.x, 0.0f  + position.y, 1.0f + position.z, 0.0, 0.0, 1.0, 0.0f + textureX, 0.0f + textureY,
				 1.0f + position.x, 0.0f  + position.y, 1.0f + position.z, 0.0, 0.0, 1.0, 1.0f + textureX, 0.0f + textureY,
				 1.0f + position.x,  1.0f + position.y, 1.0f + position.z, 0.0, 0.0, 1.0, 1.0f + textureX, 1.0f + textureY,

				 1.0f + position.x,  1.0f + position.y, 1.0f + position.z, 0.0, 0.0, 1.0, 1.0f + textureX, 1.0f + textureY,
				0.0f  + position.x,  1.0f + position.y, 1.0f + position.z, 0.0, 0.0, 1.0, 0.0f + textureX, 1.0f + textureY,
				0.0f  + position.x, 0.0f  + position.y, 1.0f + position.z, 0.0, 0.0, 1.0, 0.0f + textureX, 0.0f + textureY
			};
		}
		else if(cubeSide == CubeSide::Back) {
			return {
				 1.0f + position.x,  1.0f + position.y, 0.0f  + position.z, 0.0, 0.0, -1.0, 1.0f + textureX, 1.0f + textureY,
				 1.0f + position.x, 0.0f  + position.y, 0.0f  + position.z, 0.0, 0.0, -1.0, 1.0f + textureX, 0.0f + textureY,
				0.0f  + position.x, 0.0f  + position.y, 0.0f  + position.z, 0.0, 0.0, -1.0, 0.0f + textureX, 0.0f + textureY,

				0.0f  + position.x, 0.0f  + position.y, 0.0f  + position.z, 0.0, 0.0, -1.0, 0.0f + textureX, 0.0f + textureY,
				0.0f  + position.x,  1.0f + position.y, 0.0f  + position.z, 0.0, 0.0, -1.0, 0.0f + textureX, 1.0f + textureY,
				 1.0f + position.x,  1.0f + position.y, 0.0f  + position.z, 0.0, 0.0, -1.0, 1.0f + textureX, 1.0f + textureY
			};
		}
		else if(cubeSide == CubeSide::Left) {
			return {
				0.0f  + position.x, 0.0f  + position.y, 0.0f  + position.z, -1.0, 0.0, 0.0, 0.0f + textureX, 0.0f + textureY,
				0.0f  + position.x, 0.0f  + position.y,  1.0f + position.z, -1.0, 0.0, 0.0, 1.0f + textureX, 0.0f + textureY,
				0.0f  + position.x,  1.0f + position.y,  1.0f + position.z, -1.0, 0.0, 0.0, 1.0f + textureX, 1.0f + textureY,

				0.0f  + position.x,  1.0f + position.y,  1.0f + position.z, -1.0, 0.0, 0.0, 1.0f + textureX, 1.0f + textureY,
				0.0f  + position.x,  1.0f + position.y, 0.0f  + position.z, -1.0, 0.0, 0.0, 0.0f + textureX, 1.0f + textureY,
				0.0f  + position.x, 0.0f  + position.y, 0.0f  + position.z, -1.0, 0.0, 0.0, 0.0f + textureX, 0.0f + textureY
			};
		}
		else if(cubeSide == CubeSide::Right) {
			return {
				1.0f + position.x,  1.0f + position.y,  1.0f + position.z, 1.0, 0.0, 0.0, 1.0f + textureX, 1.0f + textureY,
				1.0f + position.x, 0.0f  + position.y,  1.0f + position.z, 1.0, 0.0, 0.0, 1.0f + textureX, 0.0f + textureY,
				1.0f + position.x, 0.0f  + position.y, 0.0f  + position.z, 1.0, 0.0, 0.0, 0.0f + textureX, 0.0f + textureY,

				1.0f + position.x, 0.0f  + position.y, 0.0f  + position.z, 1.0, 0.0, 0.0, 0.0f + textureX, 0.0f + textureY,
				1.0f + position.x,  1.0f + position.y, 0.0f  + position.z, 1.0, 0.0, 0.0, 0.0f + textureX, 1.0f + textureY,
				1.0f + position.x,  1.0f + position.y,  1.0f + position.z, 1.0, 0.0, 0.0, 1.0f + textureX, 1.0f + textureY
			};
		}
		else if(cubeSide == CubeSide::Top) {
			return {
				0.0f  + position.x,  1.0f + position.y,  1.0f + position.z, 0.0, 1.0, 0.0, 0.0f + textureX, 0.0f + textureY,
				 1.0f + position.x,  1.0f + position.y,  1.0f + position.z, 0.0, 1.0, 0.0, 1.0f + textureX, 0.0f + textureY,
				 1.0f + position.x,  1.0f + position.y, 0.0f  + position.z, 0.0, 1.0, 0.0, 1.0f + textureX, 1.0f + textureY,

				 1.0f + position.x,  1.0f + position.y, 0.0f  + position.z, 0.0, 1.0, 0.0, 1.0f + textureX, 1.0f + textureY,
				0.0f  + position.x,  1.0f + position.y, 0.0f  + position.z, 0.0, 1.0, 0.0, 0.0f + textureX, 1.0f + textureY,
				0.0f  + position.x,  1.0f + position.y,  1.0f + position.z, 0.0, 1.0, 0.0, 0.0f + textureX, 0.0f + textureY
			};
		}
		else {
			return {
				 1.0f + position.x, 0.0f  + position.y, 0.0f  + position.z, 0.0, -1.0, 0.0, 1.0f + textureX, 1.0f + textureY,
				 1.0f + position.x, 0.0f  + position.y,  1.0f + position.z, 0.0, -1.0, 0.0, 1.0f + textureX, 0.0f + textureY,
				0.0f  + position.x, 0.0f  + position.y,  1.0f + position.z, 0.0, -1.0, 0.0, 0.0f + textureX, 0.0f + textureY,

				0.0f  + position.x, 0.0f  + position.y,  1.0f + position.z, 0.0, -1.0, 0.0, 0.0f + textureX, 0.0f + textureY,
				0.0f  + position.x, 0.0f  + position.y, 0.0f  + position.z, 0.0, -1.0, 0.0, 0.0f + textureX, 1.0f + textureY,
				 1.0f + position.x, 0.0f  + position.y, 0.0f  + position.z, 0.0, -1.0, 0.0, 1.0f + textureX, 1.0f + textureY
			};
		}
	}
};

class Chunk {
public:
	Chunk(int chunkX, int chunkZ);
	~Chunk();

	bool isSolid(int x, int y, int z);
	inline const Block& getBlock(int x, int y, int z) {
		Vector4i segPos = calculateSegmentPosFromChunkPos(x, y, z);
		// std::cout << x << ", " << y << ", " << z << " :::: " << segPos.x << ", " << segPos.y << ", " << segPos.z << ", " << segPos.w << std::endl;
		return BlockManager::getBlock(blocks[segPos.w][segPos.x][segPos.y][segPos.z]);
	}
	void changeBlock(int x, int y, int z, BlockId blockId);

	inline float* getChunkSegmentData(int index) { return &chunkMesh[index][0][0]; }
	inline int getChunkSegmentMeshVerticiesCount(int index) const { return chunkMesh[index].size() * 6; }
	inline int getChunkMeshVerticiesCount() const { return chunkMeshSize; }

private:
	void generateChunkMesh();
	void generateChunkSegmentMesh(int index);
	void updateChunkMesh(int x, int y, int z);
	Vector4i calculateSegmentPosFromChunkPos(int x, int y, int z);

public:
	const int chunkX, chunkZ;
	BlockId blocks[CHUNK_SEGMENTS][CHUNK_WIDTH][CHUNK_SEGMENT_HEIGHT][CHUNK_WIDTH];
	std::array<std::vector<std::array<float, 48>>, CHUNK_SEGMENTS> chunkMesh;
	int chunkMeshSize;
	Chunk* next = nullptr;

	friend class World;

};