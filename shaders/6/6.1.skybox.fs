#version 330 core
out vec4 FragColor;

in vec3 TexCoords;

uniform samplerCube skybox;

void main()
{    
  // ͨ����������������ͨ��samplerCube�������͵������Ϳ��Բ�������ɫֵ����Ϊ���
    FragColor = texture(skybox, TexCoords);
}