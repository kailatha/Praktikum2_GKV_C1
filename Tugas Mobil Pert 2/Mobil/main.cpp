#include <GL/glut.h>
#include <math.h>

// Fungsi untuk awan
void drawCloud(float centerX, float centerY, float scale) {
    float cloudColor[3] = {1.0f, 1.0f, 1.0f};
    glColor3fv(cloudColor);
    
    // Overlapping lingkaran untuk awan
    float positions[5][2] = {
        {centerX, centerY},
        {centerX - 0.08f * scale, centerY - 0.02f * scale},
        {centerX + 0.08f * scale, centerY - 0.01f * scale},
        {centerX - 0.14f * scale, centerY + 0.03f * scale},
        {centerX + 0.14f * scale, centerY + 0.02f * scale}
    };
    
    float radii[5] = {
        0.08f * scale,
        0.07f * scale,
        0.07f * scale,
        0.06f * scale,
        0.06f * scale
    };
    
    for (int c = 0; c < 5; c++) {
        glBegin(GL_POLYGON);
        for (int i = 0; i <= 360; i += 10) {
            float angle = i * M_PI / 180.0f;
            glVertex2f(positions[c][0] + radii[c] * cos(angle), 
                       positions[c][1] + radii[c] * sin(angle));
        }
        glEnd();
    }
}

// Fungsi untuk rumah 
void drawHouse(float x, float y, float scale, float r, float g, float b) {
    // Body rumah 
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x - 0.12f * scale, y - 0.12f * scale);
    glVertex2f(x + 0.12f * scale, y - 0.12f * scale);
    glVertex2f(x + 0.12f * scale, y + 0.08f * scale);
    glVertex2f(x - 0.12f * scale, y + 0.08f * scale);
    glEnd();
    
    // Atap
    glColor3f(r * 0.7f, g * 0.7f, b * 0.7f);
    glBegin(GL_TRIANGLES);
    glVertex2f(x - 0.14f * scale, y + 0.08f * scale);
    glVertex2f(x + 0.14f * scale, y + 0.08f * scale);
    glVertex2f(x, y + 0.22f * scale);
    glEnd();
    
    // pintu
    glColor3f(r * 0.6f, g * 0.6f, b * 0.6f);
    glBegin(GL_QUADS);
    glVertex2f(x - 0.03f * scale, y - 0.12f * scale);
    glVertex2f(x + 0.03f * scale, y - 0.12f * scale);
    glVertex2f(x + 0.03f * scale, y - 0.02f * scale);
    glVertex2f(x - 0.03f * scale, y - 0.02f * scale);
    glEnd();
    
    // jendela
    glColor3f(0.8f, 0.9f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(x - 0.09f * scale, y - 0.02f * scale);
    glVertex2f(x - 0.01f * scale, y - 0.02f * scale);
    glVertex2f(x - 0.01f * scale, y + 0.04f * scale);
    glVertex2f(x - 0.09f * scale, y + 0.04f * scale);
    glEnd();
    
    // jendela2
    glBegin(GL_QUADS);
    glVertex2f(x + 0.01f * scale, y - 0.02f * scale);
    glVertex2f(x + 0.09f * scale, y - 0.02f * scale);
    glVertex2f(x + 0.09f * scale, y + 0.04f * scale);
    glVertex2f(x + 0.01f * scale, y + 0.04f * scale);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Langit 
    glColor3f(0.56f, 0.85f, 0.85f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -1.0f);  
    glVertex2f(1.0f, -1.0f);  
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();
    
    // Matahari
    glColor3f(1.0f, 0.9f, 0.0f);
    glBegin(GL_POLYGON);
    float sunX = 0.8f;
    float sunY = 0.7f;
    float sunRadius = 0.15f;
    for (int i = 0; i <= 360; i += 10) {
        float angle = i * M_PI / 180.0f;
        glVertex2f(sunX + sunRadius * cos(angle), sunY + sunRadius * sin(angle));
    }
    glEnd();
    
    // Awan
    drawCloud(-0.6f, 0.6f, 1.0f);  //kiri
    drawCloud(0.4f, 0.7f, 1.2f);   // kanan
    drawCloud(-0.2f, 0.8f, 0.8f);  // tengah
    
    // Tanah(rumput)
    glColor3f(0.36f, 0.58f, 0.36f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(-1.0f, -0.1f);
    glEnd();
    
    // posisi rumah di atas tanah
    drawHouse(-0.75f, -0.1f, 0.85f, 0.9f, 0.6f, 0.6f);  // pink 
    drawHouse(-0.35f, -0.1f, 0.8f, 0.6f, 0.8f, 0.9f);   // biru 
    drawHouse(0.35f, -0.1f, 0.85f, 0.9f, 0.9f, 0.6f);   // kuning
    drawHouse(0.75f, -0.1f, 0.8f, 0.7f, 0.9f, 0.7f);    // hujau
    
    // jalan
    glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.85f);
    glVertex2f(1.0f, -0.85f);
    glVertex2f(1.0f, -0.35f);
    glVertex2f(-1.0f, -0.35f);
    glEnd();
    
    // garis putus putus
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = -5; i < 5; i++) {
        glBegin(GL_QUADS);
        glVertex2f(i * 0.4f, -0.61f);
        glVertex2f(i * 0.4f + 0.2f, -0.61f);
        glVertex2f(i * 0.4f + 0.2f, -0.59f);
        glVertex2f(i * 0.4f, -0.59f);
        glEnd();
    }
    
    // Untuk merotasi mobil 
    glRotatef(7, 0.0f, 0.0f, 1.0f);
    
    // Mobil
    float carScale = 1.3f;  
    
    // body mobil bawah 
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.6f, 0.8f); 
    glVertex2f(-0.4f * carScale, -0.48f);
    glVertex2f(0.4f * carScale, -0.48f);
    glColor3f(0.9f, 0.4f, 0.8f); 
    glVertex2f(0.4f * carScale, -0.68f);
    glVertex2f(-0.4f * carScale, -0.68f);
    glEnd();
    
    // body mobil atas
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.7f, 0.9f); 
    glVertex2f(-0.2f * carScale, -0.28f);
    glVertex2f(0.2f * carScale, -0.28f);
    glColor3f(0.8f, 0.6f, 0.8f); 
    glVertex2f(0.3f * carScale, -0.48f);
    glVertex2f(-0.3f * carScale, -0.48f);
    glEnd();
    
    // jendela mobil kiri
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f); 
    glVertex2f(-0.18f * carScale, -0.31f);
    glVertex2f(-0.02f * carScale, -0.31f);
    glColor3f(0.9f, 0.95f, 1.0f); 
    glVertex2f(-0.02f * carScale, -0.47f);
    glVertex2f(-0.26f * carScale, -0.47f);
    glEnd();
    
    // jendela mobil kiri
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f); 
    glVertex2f(0.02f * carScale, -0.31f);
    glVertex2f(0.18f * carScale, -0.31f);
    glColor3f(0.9f, 0.95f, 1.0f); 
    glVertex2f(0.26f * carScale, -0.47f);
    glVertex2f(0.02f * carScale, -0.47f);
    glEnd();
    
    // jendela divider
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.7f, 0.9f); 
    glVertex2f(-0.02f * carScale, -0.29f);
    glVertex2f(0.02f * carScale, -0.29f);
    glColor3f(0.8f, 0.6f, 0.8f); 
    glVertex2f(0.02f * carScale, -0.47f);
    glVertex2f(-0.02f * carScale, -0.47f);
    glEnd();
    
    // Roda kiri
    glBegin(GL_POLYGON);
    float leftWheelX = -0.25f * carScale;
    float wheelY = -0.68f;
    float wheelRadius = 0.1f * carScale;
    for (int i = 0; i <= 360; i += 5) {
        float angle = i * M_PI / 180.0f;
        float intensity = 0.3f * (1.0f + sin(angle)) / 2.0f;
        glColor3f(intensity, intensity, intensity);
        glVertex2f(leftWheelX + wheelRadius * cos(angle), wheelY + wheelRadius * sin(angle));
    }
    glEnd();
    
    // Roda kanan
    glBegin(GL_POLYGON);
    float rightWheelX = 0.25f * carScale;
    for (int i = 0; i <= 360; i += 5) {
        float angle = i * M_PI / 180.0f;
        float intensity = 0.3f * (1.0f + sin(angle)) / 2.0f;
        glColor3f(intensity, intensity, intensity);
        glVertex2f(rightWheelX + wheelRadius * cos(angle), wheelY + wheelRadius * sin(angle));
    }
    glEnd();
    
    // Roda kiri
    glBegin(GL_POLYGON);
    float hubRadius = 0.05f * carScale;
    for (int i = 0; i <= 360; i += 5) {
        float angle = i * M_PI / 180.0f;
        float intensity = 0.5f + 0.3f * sin(angle);
        glColor3f(intensity, intensity, intensity);
        glVertex2f(leftWheelX + hubRadius * cos(angle), wheelY + hubRadius * sin(angle));
    }
    glEnd();
    
    // Roda kanan
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i += 5) {
        float angle = i * M_PI / 180.0f;

        float intensity = 0.5f + 0.3f * sin(angle);
        glColor3f(intensity, intensity, intensity);
        glVertex2f(rightWheelX + hubRadius * cos(angle), wheelY + hubRadius * sin(angle));
    }
    glEnd();
    
    // Lampu belakang
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.3f, 0.0f); 
    glVertex2f(-0.4f * carScale, -0.55f);
    glVertex2f(-0.37f * carScale, -0.55f);
    glColor3f(1.0f, 0.0f, 0.0f); 
    glVertex2f(-0.37f * carScale, -0.61f);
    glVertex2f(-0.4f * carScale, -0.61f);
    glEnd();
    
    // Lampu depan
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.7f); 
    glVertex2f(0.37f * carScale, -0.55f);
    glVertex2f(0.4f * carScale, -0.55f);
    glColor3f(1.0f, 1.0f, 1.0f); 
    glVertex2f(0.4f * carScale, -0.61f);
    glVertex2f(0.37f * carScale, -0.61f);
    glEnd();
    
    
    glutSwapBuffers();
    
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("2D Mobil");
    
    glutDisplayFunc(display);
    
    // Background color 
    glClearColor(0.56f, 0.85f, 0.85f, 1.0f);
    
    glutMainLoop();
    return 0;
}
