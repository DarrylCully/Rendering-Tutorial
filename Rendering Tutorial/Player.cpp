#include "Player.h"


/*

Name: Brodie Frail

Student ID: B00369676

I declare that the following code was produced by Brodie Frail and Daryyl Cully as a group assignment for the Real Time graphics module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

//
//void Player::Draw(Shader &shader) {
//	Player::m_Body->Draw(shader);
//}
//
//void Player::Update(Shader &shader, glm::mat4 &Projection, glm::mat4 &View) {
//	Player::m_Body->m_Model = glm::mat4(1.0f);
//	Player::m_Body->m_Model = glm::translate(Player::m_Body->m_Model, Player::m_Camera->GetPos()); // Supposed to set the shotgun'
//
//	glm::vec3 c_Perp = glm::normalize(Player::m_Camera->Right); // Get normalised vectors for positioning
//	glm::vec3 c_Down = glm::normalize(-Player::m_Camera->Up);
//	glm::vec3 c_front = glm::normalize(Player::m_Camera->Front);
//
//	c_Perp *= 0.15;
//	c_Down *= 0.2;  //Scale Normalised vectors for positioning and offsets
//	c_front *= 0.5;
//
//	Player::m_Body->m_Model = glm::translate(Player::m_Body->m_Model, c_Perp);
//	Player::m_Body->m_Model = glm::translate(Player::m_Body->m_Model, c_Down);	//apply normalised vectors as transformations to the model matrix
//	Player::m_Body->m_Model = glm::translate(Player::m_Body->m_Model, c_front);
//
//	float CamPitch = Player::m_Camera->Pitch;
//	float CamYaw = Player::m_Camera->Yaw;
//
//
//	Player::m_Body->m_Model = glm::scale(Player::m_Body->m_Model, glm::vec3(0.1f, 0.1f, 0.1f));
//
//
//	Player::m_Body->m_Model = glm::rotate(Player::m_Body->m_Model, glm::radians(-CamYaw), glm::vec3(0, 1.0, 0)); //rotate gun around the y-axis
//	Player::m_Body->m_Model = glm::rotate(Player::m_Body->m_Model, sin(glm::radians(CamPitch)) , glm::vec3(0, 0, 1.0)); //rotate gun around the z-axis
//
//
//	shader.Use();
//	shader.SetMat4("model", Player::m_Body->m_Model);
//	shader.SetMat4("projection", Projection);
//	shader.SetMat4("view", View);
//
//}