#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
//#include<gl/GL.h>
//#include <random>
#include "Shader.h"
#include "stb_image.h"
#include <iostream>

void framebuffer_size_callback(GLFWwindow* m_Window, int m_Width, int m_Height);
void mouse_Callback(GLFWwindow* m_Window, double m_Xpos, double m_YPos);
void Input(GLFWwindow* m_Window);

int InitVBO(); 
int InitVAO();
int InitTexture(); 
void Render();
void Draw(Shader& m_MyShader); 

float R = 0.5f; float G = 0.5f; float B = 0.5f; float A = 0.1f;

float m_Vertices[] = {
		 -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
};

glm::vec3 m_CubePos[] = {
	/*glm::vec3((rand() % 11) -5, (rand() % 11) - 5, (rand() % 16)-15),
	glm::vec3((rand() % 11) - 5, (rand() % 11) - 5, (rand() % 16) - 15),
	glm::vec3((rand() % 11) - 5, (rand() % 11) - 5, (rand() % 16) - 15),
	glm::vec3((rand() % 11) - 5, (rand() % 11) - 5, (rand() % 16) - 15),
	glm::vec3((rand() % 11) - 5, (rand() % 11) - 5, (rand() % 16) - 15),
	glm::vec3((rand() % 11) - 5, (rand() % 11) - 5, (rand() % 16) - 15),
	glm::vec3((rand() % 11) - 5, (rand() % 11) - 5, (rand() % 16) - 15),
	glm::vec3((rand() % 11) - 5, (rand() % 11) - 5, (rand() % 16) - 15),
	glm::vec3((rand() % 11) - 5, (rand() % 11) - 5, (rand() % 16) - 15),
	glm::vec3((rand() % 11) - 5, (rand() % 11) - 5, (rand() % 16) - 15)*/

	glm::vec3(0.0f,  0.0f,  0.0f),
	glm::vec3(2.0f,  5.0f, -15.0f),
	glm::vec3(-1.5f, -2.2f, -2.5f),
	glm::vec3(-3.8f, -2.0f, -12.3f),
	glm::vec3(2.4f, -0.4f, -3.5f),
	glm::vec3(-1.7f,  3.0f, -7.5f),
	glm::vec3(1.3f, -2.0f, -2.5f),
	glm::vec3(1.5f,  2.0f, -2.5f),
	glm::vec3(1.5f,  0.2f, -1.5f),
	glm::vec3(-1.3f,  1.0f, -1.5f)
};

unsigned int m_Indices[] = {
	0, 1, 3,
	1, 2, 3
};

bool m_FirstMouse = true;

unsigned int VBO;
unsigned int VAO;
unsigned int EBO;
unsigned int m_Texture1, m_Texture2;

unsigned char* m_Data;

float m_Width = 800.0f;
float m_Height = 600.0f;
float m_DeltaTime = 0.0f;
float m_LastFrame = 0.0f;
float m_CurrentFrame = 0.0f;
float m_MouseLastX = m_Width / 2;
float m_MouseLastY = m_Height / 2;
float m_Pitch = 0.0f;
float m_Yaw = -90.0f;

int m_TextureWidth, m_TextureHeight, m_nrChannels;

glm::mat4 m_Model = glm::mat4(1.0f);
glm::mat4 m_View = glm::mat4(1.0f);
glm::mat4 m_Proj = glm::mat4(1.0f);

glm::vec3 m_CameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 m_CameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 m_CameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
glm::vec3 m_Direction = glm::vec3(1.0f);

int InitVBO() {
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_Vertices), m_Vertices, GL_STATIC_DRAW);
	return 1;
}


int InitVAO() {
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	return 1;
}

int InitEBO() {
	glGenBuffers(1, &EBO);
	glGenVertexArrays(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_Indices), m_Indices, GL_STATIC_DRAW);
	return 1;
}


void Render() {

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindVertexArray(0);
}


int InitTexture() {
	glGenTextures(1, &m_Texture1);
	glBindTexture(GL_TEXTURE_2D, m_Texture1);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stbi_set_flip_vertically_on_load(true);

	m_Data = stbi_load("Textures//Greed.jpg", &m_TextureWidth, &m_TextureHeight, &m_nrChannels, 0);

	//std::cout << *m_Data << std::endl;

	if (m_Data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_TextureWidth, m_TextureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, m_Data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "The texture1 cannae take it cap'n!" << std::endl;
	}
	stbi_image_free(m_Data);

	glGenTextures(1, &m_Texture2);
	glBindTexture(GL_TEXTURE_2D, m_Texture2);
	

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stbi_set_flip_vertically_on_load(true);

	m_Data = stbi_load("Textures//Lust.jpg", &m_TextureWidth, &m_TextureHeight, &m_nrChannels, 0);

	//std::cout << *m_Data << std::endl;

	if (m_Data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_TextureWidth, m_TextureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, m_Data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "The texture2 cannae take it cap'n!" << std::endl;
	}
	stbi_image_free(m_Data);
	return 1;
}


int main_1() {
	glm::vec4 colour = glm::vec4(0.008f, 0.012f, 0.016f, 0.004f);

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* m_Window = glfwCreateWindow(m_Width, m_Height, "window 10", NULL, NULL);

	if (m_Window == NULL) {
		std::cout << "Window Broke" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(m_Window);
	glfwSetFramebufferSizeCallback(m_Window, framebuffer_size_callback);
	glfwSetCursorPosCallback(m_Window, mouse_Callback);
	
	glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "GLAD-ly failed initialisation" << std::endl;
		return -1;
	}

	glEnable(GL_DEPTH_TEST);
	
	Shader m_MyShader("Vertex.txt", "Fragment.txt");
	InitVBO();
	InitVAO();
	//InitEBO();
	Render();
	InitTexture();

	m_MyShader.Use();
	//glUniform1i(glGetUniformLocation(m_MyShader.m_ID, "texture1"), 0);
	m_MyShader.Setint("texture1", 0);
	m_MyShader.Setint("texture2", 1);

	//glViewport(0, 0, 800, 600);

	

	while (!glfwWindowShouldClose(m_Window)) {
		

		m_CurrentFrame = glfwGetTime();
		m_DeltaTime = m_CurrentFrame - m_LastFrame;
		m_LastFrame = m_CurrentFrame;
		
		Input(m_Window);

		

		glClearColor(R, G, B, A);
		//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, m_Texture1);

		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, m_Texture2);


		m_MyShader.Use();
		m_Proj = glm::perspective(glm::radians(45.0f), (float)m_Width / (float)m_Height, 0.1f, 100.0f);
		m_MyShader.SetMat4("projection", m_Proj);


		m_View = glm::lookAt(m_CameraPos, m_CameraPos+m_CameraFront, m_CameraUp);
		//m_View = glm::translate(m_View, glm::vec3(0.0f, 0.0f, -3.0f));
		/*std::cout << "View Matrix: \n" << m_View[0][0] << ", " << m_View[0][1] << ", " << m_View[0][2] << ", " << m_View[0][3] << "\n "
			<< m_View[1][0] << ", " << m_View[1][1] << ", " << m_View[1][2] << ", " << m_View[1][3] << "\n "
			<< m_View[2][0] << ", " << m_View[2][1] << ", " << m_View[2][2] << ", " << m_View[2][3] << "\n "
			<< m_View[3][0] << ", " << m_View[3][1] << ", " << m_View[3][2] << ", " << m_View[3][3] << std::endl;*/

		std::cout << m_CameraPos.x << ", " << m_CameraPos.y << ", " << m_CameraPos.z << std::endl;
		m_MyShader.SetMat4("view", m_View);
		
		Draw(m_MyShader);
		

		glfwSwapBuffers(m_Window);
		glfwPollEvents();
		R += colour.x; G += colour.y; B += colour.z;
		if (R > 1.0f || R < 0.1f) {
			colour.x *= -1;
		}
		else if (G > 1.0f || G < 0.1f) {
			colour.y *= -1;
		}
		else if (B > 1.0f || B < 0.1f) {
			colour.z *= -1;
		}
		else if (A > 1.0f || A < 0.1f) {
			colour.w *= -1;
		}


	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glfwTerminate();
	return 0;
}


void Draw(Shader &m_MyShader) {
	//m_MyShader.Use();
	glBindVertexArray(VAO);
	for (unsigned int i = 0; i < 10; i += 1) {
		m_Model = glm::translate(m_Model, m_CubePos[i]);
		float angle = 20.0f * i;
		m_Model = glm::rotate(m_Model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));

		/*std::cout << "Model Matrix: \n" << m_Model[0][0] << ", " << m_Model[0][1] << ", " << m_Model[0][2] << ", " << m_Model[0][3] << "\n "
			<< m_Model[1][0] << ", " << m_Model[1][1] << ", " << m_Model[1][2] << ", " << m_Model[1][3] << "\n "
			<< m_Model[2][0] << ", " << m_Model[2][1] << ", " << m_Model[2][2] << ", " << m_Model[2][3] << "\n "
			<< m_Model[3][0] << ", " << m_Model[3][1] << ", " << m_Model[3][2] << ", " << m_Model[3][3] << std::endl;*/

		m_MyShader.SetMat4("model", m_Model);

		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
	
}


void framebuffer_size_callback(GLFWwindow* m_Window, int m_Width, int m_Height) {

	glViewport(0, 0, m_Width, m_Height);

}


void Input(GLFWwindow* m_Window) {
	float m_CameraSpeed = 2.5f * m_DeltaTime;
	if (glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(m_Window, true);
	}
	/*

	if (glfwGetKey(m_Window, GLFW_KEY_W) == GLFW_PRESS) {
		m_CameraPos += m_CameraSpeed * m_CameraFront;
	}
	if (glfwGetKey(m_Window, GLFW_KEY_S) == GLFW_PRESS) {
		m_CameraPos -= m_CameraSpeed * m_CameraFront;
	}
	if (glfwGetKey(m_Window, GLFW_KEY_A) == GLFW_PRESS) {
		m_CameraPos -= glm::normalize(glm::cross(m_CameraFront, m_CameraUp)) * m_CameraSpeed;
	}
	if (glfwGetKey(m_Window, GLFW_KEY_D) == GLFW_PRESS) {
		m_CameraPos += glm::normalize(glm::cross(m_CameraFront, m_CameraUp)) * m_CameraSpeed;
	}*/
}

void mouse_Callback(GLFWwindow* m_Window, double m_XPos, double m_YPos) {
	/*
	if (m_FirstMouse) {
		m_MouseLastX = m_XPos;
		m_MouseLastY = m_YPos;
		m_FirstMouse = false;
	}
	
	
	
	float m_XOffset = m_XPos - m_MouseLastX;
	float m_YOffset = m_MouseLastY - m_YPos;

	m_MouseLastX = m_XPos;
	m_MouseLastY = m_YPos;

	float m_Sensitivity = 1.0f;
	m_XOffset *= m_Sensitivity;
	m_YOffset *= m_Sensitivity;

	m_Yaw += m_XOffset;
	m_Pitch += m_YOffset;

	if (m_Pitch > 89.0f) {
		m_Pitch = 89.0f;
	}
	if (m_Pitch < -89.0f) {
		m_Pitch = -89.0f;
	}

	glm::vec3 m_Front;
	m_Front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
	m_Front.y = sin(glm::radians(m_Pitch));
	m_Front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));

	m_CameraFront = glm::normalize(m_Front);*/


}