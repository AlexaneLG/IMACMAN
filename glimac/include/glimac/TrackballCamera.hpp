#include <GL/glew.h>
#include <glimac/glm.hpp>
class TrackballCamera{
	private:
		float m_fDistance;
		float m_fAngleX;
		float m_fAngleY;
	public:
		TrackballCamera(float fDistance = 5, float fAngleX = 0, float fAngleY = 0): m_fDistance(fDistance), m_fAngleX(fAngleX), m_fAngleY(fAngleY){

		}

		void moveFront(float delta){
			m_fDistance += delta;
		}

		void rotateLeft(float degrees){
			m_fAngleY += degrees;
		}

		void rotateUp(float degrees){
			m_fAngleX += degrees;
		}

		glm::mat4 getViewMatrix() const {
			glm::mat4 viewMatrix = glm::mat4(1);
			viewMatrix = glm::translate(viewMatrix, glm::vec3(0,0, m_fDistance));
			viewMatrix = glm::rotate(viewMatrix, glm::radians(m_fAngleX), glm::vec3(1, 0, 0));
			viewMatrix = glm::rotate(viewMatrix, glm::radians(m_fAngleY), glm::vec3(0, 1, 0));
			return viewMatrix;
		}


};