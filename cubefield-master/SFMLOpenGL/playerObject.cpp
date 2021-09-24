#include <PlayerObject.h>

PlayerObject::PlayerObject()
{
	// Copy the Cube contents into GameObject
	memcpy(this->vertex, vertices, sizeof(this->vertex));
	memcpy(this->color, colors, sizeof(this->color));
	memcpy(this->uv, uvs, sizeof(this->uv));

	// Copy UV's to all faces
	for (int i = 1; i < 6; i++)
		memcpy(&uv[i * 4 * 2], &uv[0], 2 * 4 * sizeof(GLfloat));

	memcpy(this->index, indices, sizeof(this->index));

	this->position = vec3();
}

PlayerObject::~PlayerObject()
{
}

vec3 PlayerObject::getPosition() { return this->position; }
void PlayerObject::setPosition(vec3 position) { this->position = position; }

// Returns the first element of the Vertex array
GLfloat* PlayerObject::getVertex() { return this->vertex; }
// 3 Vertices
int PlayerObject::getVertexCount() { return ARRAY_SIZE(vertex) / 3; }

// Returns the first element of the Color array
GLfloat* PlayerObject::getColor() { return this->color; }
// 4 Colors RGBA
int PlayerObject::getColorCount() { return ARRAY_SIZE(color) / 4; }

// Returns the first element of the UV array
GLfloat* PlayerObject::getUV() { return this->uv; }
// 3 Colors RGB
int PlayerObject::getUVCount() { return ARRAY_SIZE(uv); }

// Returns the first element of the Index array
GLfloat* PlayerObject::getIndex() { return this->index; }
// 3 Colors RGB
int PlayerObject::getIndexCount() { return ARRAY_SIZE(index) / 3; }