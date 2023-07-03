CC = g++
CFLAGS =  -std=c++11

TARGET = ASCIIrenderer
SRCDIR = pliki_cpp
OBJDIR = pliki_obiektowe
INCLUDEDIR = pliki_h


SOURCES = $(wildcard $(SRCDIR)/*.cpp) $/main.cpp
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))


$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(INCLUDEDIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDEDIR)

clean:
	rm -f $(OBJDIR)/*.o $(TARGET)

.PHONY: clean
