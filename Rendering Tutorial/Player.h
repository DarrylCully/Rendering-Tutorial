#pragma once

#include "Camera.h"
#include "Model.h"


/*

Name: Brodie Frail

Student ID: B00369676

I declare that the following code was produced by Brodie Frail and Daryyl Cully as a group assignment for the Real Time graphics module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/


class Player
{
public:
	Player(Camera* camera,Model* Body) : m_Camera(camera), m_Body(Body){}
	Camera* m_Camera;
	Model* m_Body;
	void Draw(Shader &shader);
	void Input();
	void Update(Shader &shader, glm::mat4& Projection, glm::mat4& View);
private:
	
};
