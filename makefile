# Directorios de origen y destino
SRC_DIR := src
BIN_DIR := bin
INCLUDE_DIR := include

# Librerías de SFML
SFML := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lbox2d

# Opciones del compilador
CXX := g++
CXXFLAGS := -I$(INCLUDE_DIR) -std=c++17
LDFLAGS := $(SFML) -mwindows

# Archivos fuente y objeto
CPP_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(CPP_FILES))

# Nombre del ejecutable
TARGET := $(BIN_DIR)/Juego.exe

# Regla por defecto para compilar el proyecto
all: $(TARGET)

# Regla para compilar el ejecutable
$(TARGET): $(OBJ_FILES)
	$(CXX) $^ -o $@ $(LDFLAGS)

# Regla para compilar archivos .cpp en archivos .o
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Asegurar que el directorio bin exista
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Regla para limpiar los archivos generados
clean:
	rm -f $(BIN_DIR)/*.o $(TARGET)

.PHONY: all clean
