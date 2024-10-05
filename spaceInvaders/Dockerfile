FROM debian:latest

# build and run this image like so:
#
# docker build . -t game:latest
# docker run -it -p 8080:8080 game:latest
#
# Now open a web browser from your local system and navigate to:
# http://localhost:8080/
# Find your game and run it

RUN apt update -y && \
    apt install -y build-essential gdb cmake doxygen python3 python3-pip libsdl2-dev \
    libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev git vim libxmp-dev pkg-config \
    libfluidsynth-dev fluidsynth libwavpack-dev libopusfile-dev

RUN mkdir /spaceInvaders
COPY . /spaceInvaders

# Install Emscripten
RUN git clone https://github.com/emscripten-core/emsdk.git && \
    cd emsdk && \
    ./emsdk install latest && \
    ./emsdk activate latest

# Setting environment variables for Emscripten for subsequent commands
ENV PATH="/emsdk:/emsdk/upstream/emscripten:$PATH"

# Now build your project
RUN cd /spaceInvaders && \
    emmake make web

ENTRYPOINT ["sh", "-c", "cd /spaceInvaders/build && python3 -m http.server 8080"]
