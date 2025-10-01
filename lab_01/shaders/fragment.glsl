#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D text1;
uniform sampler2D text2;

void main()
{
    vec4 c1 = texture(text1, TexCoord);
    vec4 c2 = texture(text2, TexCoord);
    FragColor = mix(c1, c2, 0.5);
}
