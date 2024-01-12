uniform sampler2D u_Texture; 
uniform vec3 u_ViewPos;      
uniform mat4 u_Viewing;      
		                             
varying vec2 v_TexCoord;     
varying vec3 v_Normal;		 
varying vec3 v_FragPos;
uniform vec3 u_LightPos;	  
		                             
void main()                  
{                            
	u_ViewPos = inverse(u_Viewing) * vec4(0,0,0,1);
		                             
	vec3 diffuseColor = vec3(1,1,1);
	vec3 ambientColor = vec3(1,0,0);
	vec3 specularColor = vec3(1,1,1);
		                             
	vec3 N = normalize(v_Normal);
	vec3 lightDir = normalize(u_LightPos - v_FragPos);
	vec3 viewDir = normalize(u_ViewPos - v_FragPos);
	vec3 reflectDir = reflect(-lightDir, N);
		                             
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
	float diff = max(dot(N, lightDir), 0.0);
	float ambientStrength = 0.1;
									  
	vec3 diffuse = diffuseColor * diff;
	vec3 ambient = ambientStrength * ambientColor;
	vec3 specular = spec * specularColor;
	vec4 tex = texture2D(u_Texture, v_TexCoord); 
		                             
	vec3 lighting = max(vec3(0,0,0), min(diffuse + ambient + specular, vec3(1,1,1)));
	//gl_FragColor = vec4(lighting, 1)*tex; 
	gl_FragColor = tex;
}    