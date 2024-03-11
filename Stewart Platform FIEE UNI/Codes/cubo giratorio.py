import pygame
import math

pygame.init()

width, height = 800, 600
window = pygame.display.set_mode((width, height))
pygame.display.set_caption("Cubo giratorio")

WHITE = (255, 255, 255) #RGB
BLACK = (0, 0, 0)

angle_x = 0
angle_y = 0
angle_z = 0

# Función para proyectar puntos 3D en el plano 2D
def project(point, win_width, win_height, fov, distance):
    x, y, z = point
    factor = fov / (distance + z)
    x = x * factor + win_width / 2
    y = -y * factor + win_height / 2
    return int(x), int(y)

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

        # Detectar teclas presionadas
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_y:
                angle_x -= 0.1  
            elif event.key == pygame.K_z:
                angle_y -= 0.1  
            elif event.key == pygame.K_x:
                angle_z += 0.1  
            elif event.key == pygame.K_j:
                angle_x += 0.1  
            elif event.key == pygame.K_k:
                angle_y += 0.1  
            elif event.key == pygame.K_i:
                angle_z -= 0.1  

    window.fill(BLACK)
    

    cube_points = [(0.75*-110,0.75*109.12,70),(0.75*110,0.75*109.12,70),(0.75*147,0.75*36.373,70),(0.75*42,0.75*-145.492,70),(0.75*-42,0.75*-145.492,70),(0.75*-147,0.75*36.373,70),
                   (0.75*-110,0.75*109.12,-70),(0.75*110,0.75*109.12,-70),(0.75*147,0.75*36.373,-70),(0.75*42,0.75*-145.492,-70),(0.75*-42,0.75*-145.492,-70),(0.75*-147,0.75*36.373,-70)] 
    rotated_points = []
    for point in cube_points:
        x, y, z = point
        # Rotación en el eje X
        x_new = x
        y_new = y * math.cos(angle_x) - z * math.sin(angle_x)
        z_new = y * math.sin(angle_x) + z * math.cos(angle_x)
        # Rotación en el eje Y
        x = x_new * math.cos(angle_y) + z_new * math.sin(angle_y)
        y = y_new
        z = -x_new * math.sin(angle_y) + z_new * math.cos(angle_y)
        # Rotación en el eje Z
        x_new = x * math.cos(angle_z) - y * math.sin(angle_z)
        y_new = x * math.sin(angle_z) + y * math.cos(angle_z)
        x, y = x_new, y_new

        rotated_points.append((x, y, z))

    
    hexagon_vertices = [project(rotated_points[i], width, height, 128, 180) for i in range(6)]
    pygame.draw.polygon(window, 'BLUE', hexagon_vertices)
    for i in range(6):
        pygame.draw.line(window, WHITE, project(rotated_points[i], width, height, 128, 180), project(rotated_points[(i + 1) % 6], width, height, 128, 180))
        pygame.draw.line(window, WHITE, project(rotated_points[i], width, height, 128, 180), project(rotated_points[i + 6], width, height, 128, 180))
        
        
        
    sphere_center = project([rotated_points[0][0]+30, rotated_points[1][0], rotated_points[2][0]], width, height, 128, 180)
    sphere_radius = 15
    pygame.draw.circle(window, 'RED', sphere_center, sphere_radius)
    
    pygame.display.flip() # actualizar la pantalla
    pygame.time.Clock().tick(60) # velocidad de rotación


pygame.quit()