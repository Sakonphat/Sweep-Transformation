#include "genmesh.h"


// ---------------------------------------------------------------
// Helper function to compute normal vector
// We need normal vector to shade the model (you will learn shading in API class)

glm::vec3 computeNormal(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3) {
	glm::vec3 v21 = v2 - v1;
	glm::vec3 v31 = v3 - v1;
	return normalize(cross(v21, v31));
}



// ---------------------------------------------------------------
// Modify this function to Implement Sweep or Revolve
// We will use Triangle list data structure to represent our polygon mesh
// (The example code generates a sphere)

void GenerateMesh(std::vector<glm::vec3> & out_vertices, std::vector<glm::vec3> & out_normals)
{
	// Clear the array first
	out_vertices.clear();
	out_normals.clear();



	//Sweep Only !
	//glm::vec3 point1, point2, point3, point4, point5, point6,
	//	point1B, point2B, point3B, point4B, point5B, point6B;
	//
	//	//font points
	//	point1.x = -6.0;
	//	point1.y = -6.0;
	//	point1.z = 3;

	//	point2.x = -2.0;
	//	point2.y = 2.0;
	//	point2.z = 3;

	//	point3.x = 0.0;
	//	point3.y = 0.0;
	//	point3.z = 3;

	//	point4.x = 5.0;
	//	point4.y = 5.0;
	//	point4.z = 3;

	//	point5.x = 0.0;
	//	point5.y = -3.0;
	//	point5.z = 3;

	//	point6.x = -2.0;
	//	point6.y = -1.5;
	//	point6.z = 3;

	//	//back 
	//	point1B.x = -6.0;
	//	point1B.y = -6.0;
	//	point1B.z = -3;

	//	point2B.x = -2.0;
	//	point2B.y = 2.0;
	//	point2B.z = -3;

	//	point3B.x = 0.0;
	//	point3B.y = 0.0;
	//	point3B.z = -3;

	//	point4B.x = 5.0;
	//	point4B.y = 5.0;
	//	point4B.z = -3;

	//	point5B.x = 0.0;
	//	point5B.y = -3.0;
	//	point5B.z = -3;

	//	point6B.x = -2.0;
	//	point6B.y = -1.5;
	//	point6B.z = -3;


	//	// build 2 traingle from 4 points on each loop
	//	// dont forget about counter clockwise ordering

	//	//square1
	//	out_vertices.push_back(point2B);
	//	out_vertices.push_back(point1B);
	//	out_vertices.push_back(point1);

	//	out_vertices.push_back(point1);
	//	out_vertices.push_back(point2);
	//	out_vertices.push_back(point2B);

	//	//square2
	//	out_vertices.push_back(point2B);
	//	out_vertices.push_back(point2);
	//	out_vertices.push_back(point3);

	//	out_vertices.push_back(point3);
	//	out_vertices.push_back(point3B);
	//	out_vertices.push_back(point2B);

	//	//square3
	//	out_vertices.push_back(point3B);
	//	out_vertices.push_back(point3);
	//	out_vertices.push_back(point4);

	//	out_vertices.push_back(point4);
	//	out_vertices.push_back(point4B);
	//	out_vertices.push_back(point3B);

	//	//square4
	//	out_vertices.push_back(point4);
	//	out_vertices.push_back(point5);
	//	out_vertices.push_back(point5B);

	//	out_vertices.push_back(point5B);
	//	out_vertices.push_back(point4B);
	//	out_vertices.push_back(point4);

	//	//square5
	//	out_vertices.push_back(point6);
	//	out_vertices.push_back(point6B);
	//	out_vertices.push_back(point5B);

	//	out_vertices.push_back(point5B);
	//	out_vertices.push_back(point5);
	//	out_vertices.push_back(point6);

	//	//square6
	//	out_vertices.push_back(point1);
	//	out_vertices.push_back(point1B);
	//	out_vertices.push_back(point6B);

	//	out_vertices.push_back(point6B);
	//	out_vertices.push_back(point6);
	//	out_vertices.push_back(point1);

	//	// compute the normal vector for each triangle
	//	// but in our OpenGL program, the normal vector is a property of a vertex
	//	// so we have to push the same normal vector to the array, one for each vertex 
	//	//1
	//	out_normals.push_back(computeNormal(point2B, point1B, point1));
	//	out_normals.push_back(computeNormal(point2B, point1B, point1));
	//	out_normals.push_back(computeNormal(point2B, point1B, point1));

	//	out_normals.push_back(computeNormal(point1, point2, point2B));
	//	out_normals.push_back(computeNormal(point1, point2, point2B));
	//	out_normals.push_back(computeNormal(point1, point2, point2B));
	//	//2
	//	out_normals.push_back(computeNormal(point2B, point2, point3));
	//	out_normals.push_back(computeNormal(point2B, point2, point3));
	//	out_normals.push_back(computeNormal(point2B, point2, point3));

	//	out_normals.push_back(computeNormal(point3, point3B, point2B));
	//	out_normals.push_back(computeNormal(point3, point3B, point2B));
	//	out_normals.push_back(computeNormal(point3, point3B, point2B));

	//	//3
	//	out_normals.push_back(computeNormal(point3B, point3, point4));
	//	out_normals.push_back(computeNormal(point3B, point3, point4));
	//	out_normals.push_back(computeNormal(point3B, point3, point4));

	//	out_normals.push_back(computeNormal(point4, point4B, point3B));
	//	out_normals.push_back(computeNormal(point4, point4B, point3B));
	//	out_normals.push_back(computeNormal(point4, point4B, point3B));

	//	//4
	//	out_normals.push_back(computeNormal(point4, point5, point5B));
	//	out_normals.push_back(computeNormal(point4, point5, point5B));
	//	out_normals.push_back(computeNormal(point4, point5, point5B));

	//	out_normals.push_back(computeNormal(point5B, point4B, point4));
	//	out_normals.push_back(computeNormal(point5B, point4B, point4));
	//	out_normals.push_back(computeNormal(point5B, point4B, point4));

	//	//5
	//	out_normals.push_back(computeNormal(point6, point6B, point5B));
	//	out_normals.push_back(computeNormal(point6, point6B, point5B));
	//	out_normals.push_back(computeNormal(point6, point6B, point5B));

	//	out_normals.push_back(computeNormal(point5B, point5, point6));
	//	out_normals.push_back(computeNormal(point5B, point5, point6));
	//	out_normals.push_back(computeNormal(point5B, point5, point6));

	//	//6
	//	out_normals.push_back(computeNormal(point1, point1B, point6B));
	//	out_normals.push_back(computeNormal(point1, point1B, point6B));
	//	out_normals.push_back(computeNormal(point1, point1B, point6B));

	//	out_normals.push_back(computeNormal(point6B, point6, point1));
	//	out_normals.push_back(computeNormal(point6B, point6, point1));
	//	out_normals.push_back(computeNormal(point6B, point6, point1));

	//	//End Sweep Only
	

	//Sweep + Trans
	//Points
	glm::vec4 Tpoint1(-6.0f, -6.0f, 3.0f, 1.0f), Tpoint2(-2.0f, 2.0f, 3.0f, 1.0f),
		Tpoint3(0.0f, 0.0f, 3.0f, 1.0f), Tpoint4(5.0f, 5.0f, 3.0f, 1.0f),
		Tpoint5(0.0f, -3.0f, 3.0f, 1.0f), Tpoint6(-2.0f, -1.5f, 3.0f, 1.0f);

	

	glm::vec3 bPoint1, bPoint2, bPoint3, bPoint4, bPoint5, bPoint6;

	//TransformedPoints
	glm::vec4 TransformedPoint1, TransformedPoint2, TransformedPoint3, TransformedPoint4, TransformedPoint5,
		TransformedPoint6;

	//identityMatrix
	glm::mat4 myIdentityMatrix = glm::mat4(1.0f);

	//Scaling
	glm::mat4 myScalingMatrix;

	//Rotation
	glm::mat4 myRotationMatrix;

	//Translation
	glm::mat4 myTranslationMatrix;

	float step = (2 * PI) / 50;
	float rot = 50.0;

	for (float i = 0; i < 2 * PI; i += step) {


		glm::vec3 point1(Tpoint1.x, Tpoint1.y, Tpoint1.z), point2(Tpoint2.x, Tpoint2.y, Tpoint2.z),
			point3(Tpoint3.x, Tpoint3.y, Tpoint3.z), point4(Tpoint4.x, Tpoint4.y, Tpoint4.z),
			point5(Tpoint5.x, Tpoint5.y, Tpoint5.z), point6(Tpoint6.x, Tpoint6.y, Tpoint6.z);

		myScalingMatrix = glm::scale(myIdentityMatrix, vec3(1.0f, 1.0f, 1.0f));
		myRotationMatrix = glm::rotate(myIdentityMatrix, rot, vec3(0.0f, 0.0f, 1.0f));
		myTranslationMatrix = glm::translate(myIdentityMatrix, vec3(0.0f, 0.0f, -0.5));

		TransformedPoint1 = myTranslationMatrix * myRotationMatrix * myScalingMatrix * Tpoint1;
		TransformedPoint2 = myTranslationMatrix * myRotationMatrix * myScalingMatrix * Tpoint2;
		TransformedPoint3 = myTranslationMatrix * myRotationMatrix * myScalingMatrix * Tpoint3;
		TransformedPoint4 = myTranslationMatrix * myRotationMatrix * myScalingMatrix * Tpoint4;
		TransformedPoint5 = myTranslationMatrix * myRotationMatrix * myScalingMatrix * Tpoint5;
		TransformedPoint6 = myTranslationMatrix * myRotationMatrix * myScalingMatrix * Tpoint6;

			bPoint1.x = TransformedPoint1.x;
			bPoint1.y = TransformedPoint1.y;
			bPoint1.z = TransformedPoint1.z;

			bPoint2.x = TransformedPoint2.x;
			bPoint2.y = TransformedPoint2.y;
			bPoint2.z = TransformedPoint2.z;

			bPoint3.x = TransformedPoint3.x;
			bPoint3.y = TransformedPoint3.y;
			bPoint3.z = TransformedPoint3.z;

			bPoint4.x = TransformedPoint4.x;
			bPoint4.y = TransformedPoint4.y;
			bPoint4.z = TransformedPoint4.z;

			bPoint5.x = TransformedPoint5.x;
			bPoint5.y = TransformedPoint5.y;
			bPoint5.z = TransformedPoint5.z;


			bPoint6.x = TransformedPoint6.x;
			bPoint6.y = TransformedPoint6.y;
			bPoint6.z = TransformedPoint6.z;

		// build 2 traingle from 4 points on each loop
		// dont forget about counter clockwise ordering

		//square1
		out_vertices.push_back(bPoint2);
		out_vertices.push_back(bPoint1);
		out_vertices.push_back(point1);

		out_vertices.push_back(point1);
		out_vertices.push_back(point2);
		out_vertices.push_back(bPoint2);

		//square2
		out_vertices.push_back(bPoint2);
		out_vertices.push_back(point2);
		out_vertices.push_back(point3);

		out_vertices.push_back(point3);
		out_vertices.push_back(bPoint3);
		out_vertices.push_back(bPoint2);

		//square3
		out_vertices.push_back(bPoint3);
		out_vertices.push_back(point3);
		out_vertices.push_back(point4);

		out_vertices.push_back(point4);
		out_vertices.push_back(bPoint4);
		out_vertices.push_back(bPoint3);

		//square4
		out_vertices.push_back(point4);
		out_vertices.push_back(point5);
		out_vertices.push_back(bPoint5);

		out_vertices.push_back(bPoint5);
		out_vertices.push_back(bPoint4);
		out_vertices.push_back(point4);

		//square5
		out_vertices.push_back(point6);
		out_vertices.push_back(bPoint6);
		out_vertices.push_back(bPoint5);

		out_vertices.push_back(bPoint5);
		out_vertices.push_back(point5);
		out_vertices.push_back(point6);

		//square6
		out_vertices.push_back(point1);
		out_vertices.push_back(bPoint1);
		out_vertices.push_back(bPoint6);

		out_vertices.push_back(bPoint6);
		out_vertices.push_back(point6);
		out_vertices.push_back(point1);

		// compute the normal vector for each triangle
		// but in our OpenGL program, the normal vector is a property of a vertex
		// so we have to push the same normal vector to the array, one for each vertex 

		//1
		out_normals.push_back(computeNormal(bPoint2, bPoint1, point1));
		out_normals.push_back(computeNormal(bPoint2, bPoint1, point1));
		out_normals.push_back(computeNormal(bPoint2, bPoint1, point1));

		out_normals.push_back(computeNormal(point1, point2, bPoint2));
		out_normals.push_back(computeNormal(point1, point2, bPoint2));
		out_normals.push_back(computeNormal(point1, point2, bPoint2));
		//2
		out_normals.push_back(computeNormal(bPoint2, point2, point3));
		out_normals.push_back(computeNormal(bPoint2, point2, point3));
		out_normals.push_back(computeNormal(bPoint2, point2, point3));

		out_normals.push_back(computeNormal(point3, bPoint3, bPoint2));
		out_normals.push_back(computeNormal(point3, bPoint3, bPoint2));
		out_normals.push_back(computeNormal(point3, bPoint3, bPoint2));

		//3
		out_normals.push_back(computeNormal(bPoint3, point3, point4));
		out_normals.push_back(computeNormal(bPoint3, point3, point4));
		out_normals.push_back(computeNormal(bPoint3, point3, point4));

		out_normals.push_back(computeNormal(point4, bPoint4, bPoint3));
		out_normals.push_back(computeNormal(point4, bPoint4, bPoint3));
		out_normals.push_back(computeNormal(point4, bPoint4, bPoint3));

		//4
		out_normals.push_back(computeNormal(point4, point5, bPoint5));
		out_normals.push_back(computeNormal(point4, point5, bPoint5));
		out_normals.push_back(computeNormal(point4, point5, bPoint5));

		out_normals.push_back(computeNormal(bPoint5, bPoint4, point4));
		out_normals.push_back(computeNormal(bPoint5, bPoint4, point4));
		out_normals.push_back(computeNormal(bPoint5, bPoint4, point4));

		//5
		out_normals.push_back(computeNormal(point6, bPoint6, bPoint5));
		out_normals.push_back(computeNormal(point6, bPoint6, bPoint5));
		out_normals.push_back(computeNormal(point6, bPoint6, bPoint5));

		out_normals.push_back(computeNormal(bPoint5, point5, point6));
		out_normals.push_back(computeNormal(bPoint5, point5, point6));
		out_normals.push_back(computeNormal(bPoint5, point5, point6));

		//6
		out_normals.push_back(computeNormal(point1, bPoint1, bPoint6));
		out_normals.push_back(computeNormal(point1, bPoint1, bPoint6));
		out_normals.push_back(computeNormal(point1, bPoint1, bPoint6));

		out_normals.push_back(computeNormal(bPoint6, point6, point1));
		out_normals.push_back(computeNormal(bPoint6, point6, point1));
		out_normals.push_back(computeNormal(bPoint6, point6, point1));

		Tpoint1 = TransformedPoint1;
		Tpoint2 = TransformedPoint2;
		Tpoint3 = TransformedPoint3;
		Tpoint4 = TransformedPoint4;
		Tpoint5 = TransformedPoint5;
		Tpoint6 = TransformedPoint6;
	}

	// End Sweep+Trans

	
	
}
