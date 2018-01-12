#include <GL/glew.h>
#include <glimac/glm.hpp>
class FreeflyCamera{
	private:
		float m_fPhi;
		float m_fTheta;
		glm::vec3 m_Position;
		glm::vec3 m_FrontVector;
		glm::vec3 m_LeftVector;
		glm::vec3 m_UpVector;

		void computeDirectionVectors(){
			m_FrontVector = glm::vec3(glm::cos(m_fTheta)*glm::sin(m_fPhi), glm::sin(m_fTheta), glm::cos(m_fTheta)*glm::cos(m_fPhi));
			m_LeftVector = glm::vec3(glm::sin(m_fPhi + glm::pi<float>()/2.0), 0, glm::cos(m_fPhi + glm::pi<float>()/2));
			m_UpVector = glm::cross(m_FrontVector, m_LeftVector);
		}
	public:
		FreeflyCamera(float fPhi = glm::pi<float>(), float fTheta = 0, glm::vec3 Position = glm::vec3(0,0,0)): m_fPhi(fPhi), m_fTheta(fTheta), m_Position(Position){
			computeDirectionVectors();
		}

		void moveLeft(float t){
			m_Position += t * m_LeftVector;
		}

		void moveFront(float t){
			m_Position += t * m_FrontVector;
		}

        void moveUp(float t){
        m_Position += t * m_UpVector;
        }

		void rotateLeft(float degrees){
			m_fPhi += glm::radians(degrees);
			computeDirectionVectors();
		}

		void rotateUp(float degrees){
			m_fTheta += glm::radians(degrees);
			computeDirectionVectors();
		}

		glm::mat4 getViewMatrix() const {
			glm::mat4 viewMatrix = glm::lookAt(m_Position, m_Position + m_FrontVector, m_UpVector);
			return viewMatrix;
		}


};