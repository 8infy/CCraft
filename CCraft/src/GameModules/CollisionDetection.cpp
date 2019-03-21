#include "CollisionDetection.h"
#include "ChunkController.h"
#define PlayerSize 0.3f //controls collision detection range.
namespace CCraft
{
	std::array<std::set<std::pair<float, float>>, WORLD_HEIGHT> CollisionDetection::collisionMap;

	void CollisionDetection::addCollisionElement(glm::vec3 coords)
	{
		collisionMap[(int)coords.y].insert(std::make_pair(coords.x, coords.z));
	}

	void CollisionDetection::removeCollisionElement(glm::vec3 coords)
	{
		collisionMap[(int)coords.y].erase(std::make_pair(coords.x, coords.z));
	}
	//should also test for the 4 blocks around the player: x+1 z-1, x-1 z-1, x+1 z+1, x-1 z+1.
	void CollisionDetection::testForCollision(glm::vec3 playerPosition, glm::vec3& directionVector, Camera_Movement direction, float velocity)
	{
		float blockX;
		float blockZ;
		float blockY;

		if (direction == FORWARD || direction == RIGHT)
		{
			playerPosition += directionVector * velocity;

			glm::vec3 tempoPlayerPositionX = playerPosition;
			glm::vec3 tempoPlayerPositionZ = playerPosition;
			
			if (directionVector.x < 0)
			{
				tempoPlayerPositionX.x -= PlayerSize;
				blockX = floor(tempoPlayerPositionX.x);
			}
			else
			{
				tempoPlayerPositionX.x += PlayerSize;
				blockX = floor(tempoPlayerPositionX.x);
			}
			
			if (tempoPlayerPositionX.y == round(tempoPlayerPositionX.y))
			{
				blockZ = floor(tempoPlayerPositionX.z);
				blockY = tempoPlayerPositionX.y;

				if (collisionMap[blockY - 1].find(std::make_pair(blockX, blockZ)) != collisionMap[blockY - 1].end())
				{
					directionVector.x = 0.0f;
				}
				if (collisionMap[blockY - 2].find(std::make_pair(blockX, blockZ)) != collisionMap[blockY - 2].end())
				{
					directionVector.x = 0.0f;
				}
			}
			else
			{
				blockZ = floor(tempoPlayerPositionX.z);
				blockY = ceil(tempoPlayerPositionX.y);

				if (collisionMap[blockY - 1].find(std::make_pair(blockX, blockZ)) != collisionMap[blockY - 1].end())
				{
					directionVector.x = 0.0f;
				}
				if (collisionMap[blockY - 2].find(std::make_pair(blockX, blockZ)) != collisionMap[blockY - 2].end())
				{
					directionVector.x = 0.0f;
				}
				if (collisionMap[blockY - 3].find(std::make_pair(blockX, blockZ)) != collisionMap[blockY - 3].end())
				{
					directionVector.x = 0.0f;
				}
			}


			if (directionVector.z < 0.0f)
			{
				tempoPlayerPositionZ.z -= PlayerSize;
				blockZ = floor(tempoPlayerPositionZ.z);
			}
			else
			{
				tempoPlayerPositionZ.z += PlayerSize;
				blockZ = floor(tempoPlayerPositionZ.z);
			}

			if (tempoPlayerPositionZ.y == round(tempoPlayerPositionZ.y))
			{

				blockX = floor(tempoPlayerPositionZ.x);
				blockY = tempoPlayerPositionZ.y;

				if (collisionMap[blockY - 1].find(std::make_pair(blockX, blockZ)) != collisionMap[blockY - 1].end())
				{
					directionVector.z = 0.0f;
				}
				if (collisionMap[blockY - 2].find(std::make_pair(blockX, blockZ)) != collisionMap[blockY - 2].end())
				{
					directionVector.z = 0.0f;
				}
			}
			else
			{
				blockX = floor(tempoPlayerPositionZ.x);
				blockY = ceil(tempoPlayerPositionZ.y);

				if (collisionMap[blockY - 1].find(std::make_pair(blockX, blockZ)) != collisionMap[blockY - 1].end())
				{
					directionVector.z = 0.0f;
				}
				if (collisionMap[blockY - 2].find(std::make_pair(blockX, blockZ)) != collisionMap[blockY - 2].end())
				{
					directionVector.z = 0.0f;
				}
				if (collisionMap[blockY - 3].find(std::make_pair(blockX, blockZ)) != collisionMap[blockY - 3].end())
				{
					directionVector.z = 0.0f;
				}
			}
			std::cout << directionVector.x << "\n";
			std::cout << directionVector.z;
		}
		
		if (direction == BACKWARD || direction == LEFT)
		{
			playerPosition -= directionVector * velocity;

			glm::vec3 tempoPlayerPositionX = playerPosition;
			glm::vec3 tempoPlayerPositionZ = playerPosition;

			if (directionVector.x > 0)
			{
				tempoPlayerPositionX.x -= PlayerSize;
				blockX = floor(tempoPlayerPositionX.x);
			}
			else
			{
				tempoPlayerPositionX.x += PlayerSize;
				blockX = floor(tempoPlayerPositionX.x);
			}

			if (tempoPlayerPositionX.y == round(tempoPlayerPositionX.y))
			{
				blockZ = floor(tempoPlayerPositionX.z);
				blockY = tempoPlayerPositionX.y;

				if (collisionMap[blockY - 1].find(std::make_pair(blockX, blockZ)) != collisionMap[blockY - 1].end())
				{
					directionVector.x = 0.0f;
				}
				if (collisionMap[blockY - 2].find(std::make_pair(blockX, blockZ)) != collisionMap[blockY - 2].end())
				{
					directionVector.x = 0.0f;
				}
			}
			else
			{
				blockZ = floor(tempoPlayerPositionX.z);
				blockY = ceil(tempoPlayerPositionX.y);

				if (collisionMap[blockY - 1].find(std::make_pair(blockX, blockZ)) != collisionMap[blockY - 1].end())
				{
					directionVector.x = 0.0f;
				}
				if (collisionMap[blockY - 2].find(std::make_pair(blockX, blockZ)) != collisionMap[blockY - 2].end())
				{
					directionVector.x = 0.0f;
				}
				if (collisionMap[blockY - 3].find(std::make_pair(blockX, blockZ)) != collisionMap[blockY - 3].end())
				{
					directionVector.x = 0.0f;
				}
			}


			if (directionVector.z > 0.0f)
			{
				tempoPlayerPositionZ.z -= PlayerSize;
				blockZ = floor(tempoPlayerPositionZ.z);
			}
			else
			{
				tempoPlayerPositionZ.z += PlayerSize;
				blockZ = floor(tempoPlayerPositionZ.z);
			}

			if (tempoPlayerPositionZ.y == round(tempoPlayerPositionZ.y))
			{

				blockX = floor(tempoPlayerPositionZ.x);
				blockY = tempoPlayerPositionZ.y;

				if (collisionMap[blockY - 1].find(std::make_pair(blockX, blockZ)) != collisionMap[blockY - 1].end())
				{
					directionVector.z = 0.0f;
				}
				if (collisionMap[blockY - 2].find(std::make_pair(blockX, blockZ)) != collisionMap[blockY - 2].end())
				{
					directionVector.z = 0.0f;
				}
			}
			else
			{
				blockX = floor(tempoPlayerPositionZ.x);
				blockY = ceil(tempoPlayerPositionZ.y);

				if (collisionMap[blockY - 1].find(std::make_pair(blockX, blockZ)) != collisionMap[blockY - 1].end())
				{
					directionVector.z = 0.0f;
				}
				if (collisionMap[blockY - 2].find(std::make_pair(blockX, blockZ)) != collisionMap[blockY - 2].end())
				{
					directionVector.z = 0.0f;
				}
				if (collisionMap[blockY - 3].find(std::make_pair(blockX, blockZ)) != collisionMap[blockY - 3].end())
				{
					directionVector.z = 0.0f;
				}
			}
		}
	}
	
	bool CollisionDetection::testForVerticalCollision(glm::vec3 playerPosition, float velocity, Camera_Movement direction) 
	{
		float blockX;
		float blockZ;
		//should check collision for the 4 blocks above, not just 1
		if (direction == UP)
		{
			playerPosition.y += velocity;

			playerPosition.y = ceil(playerPosition.y);

			blockZ = floor(playerPosition.z);
			blockX = floor(playerPosition.x);

			if (collisionMap[(int)playerPosition.y].find(std::make_pair(blockX, blockZ)) != collisionMap[(int)playerPosition.y].end())
			{
				return false;
			}
			else
				return true;
		}
		//should check collision for the 4 blocks under, not just 1
		if (direction == DOWN)
		{
			playerPosition.y -= velocity;

			playerPosition.y = floor(playerPosition.y);

			blockZ = floor(playerPosition.z);
			blockX = floor(playerPosition.x);

			if (collisionMap[(int)playerPosition.y - 2].find(std::make_pair(blockX, blockZ)) != collisionMap[(int)playerPosition.y - 2].end())
			{
				if (collisionMap[(int)playerPosition.y - 1].find(std::make_pair(blockX, blockZ)) != collisionMap[(int)playerPosition.y - 1].end())
				{
					return false;
				}
					
			}
			else
				return true;
		}
	}

	void CollisionDetection::placeBlock(glm::vec3 startingPosition, glm::vec3 ray)
	{
		startingPosition.x = round(startingPosition.x);
		startingPosition.z = round(startingPosition.z);
		std::cout << startingPosition.x << " " << startingPosition.y << " " << startingPosition.z << "\n";
		for (int i = 0; i < 3; i++)
		{
			startingPosition += ray * 1.0f;
			auto rayTarget = startingPosition;
			rayTarget.x = round(rayTarget.x);
			rayTarget.y = round(rayTarget.y);
			rayTarget.z = round(rayTarget.z);
			rayTarget.y -= 1.0f;
			auto block = collisionMap[rayTarget.y].find(std::make_pair(rayTarget.x, rayTarget.z));
			if (block != collisionMap[rayTarget.y].end())
			{
				std::cout << "FOUND A BLOCK AT: " << rayTarget.x << " " << rayTarget.y - 1 << " " << rayTarget.z << "\n";
				ChunkController::removeBlock(rayTarget);
				collisionMap[rayTarget.y].erase(block);
				break;
			}
			else
			std::cout << "DID NOT FIND A BLOCK AT: " << rayTarget.x << " " << rayTarget.y -1<< " " << rayTarget.z << "\n";
		}
	}
	void CollisionDetection::removeBlock(glm::vec3 startingPosition, glm::vec3 ray, float velocity)
	{

	}
}