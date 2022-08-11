# Base Image
FROM gcc:11 as base

RUN apt-get update && apt-get install -y --no-install-recommends \
        binutils \
        cmake \
        libboost-dev \
        ninja-build \
    && apt-get clean



FROM base as build

# Create folder for app service and change directory
WORKDIR /src/app

# Copying all the files from app to container's workdir
COPY . .

# Build the binaries
RUN mkdir build \
    && cd build \
    && cmake .. \
    && make 



# VS Code aimed Stage 
# (This is preferred to run as a Docker Dev Environment)
FROM base AS vscode

# Get packages for editors and CVS
RUN apt-get update && apt-get install -y --no-install-recommends \
        git \
    && apt-get clean

# Create and change user
ENV MYUSERNAME="vscode"

RUN useradd -s /bin/bash -m $MYUSERNAME \
    && groupadd docker \
    && usermod -aG docker $MYUSERNAME

USER $MYUSERNAME

# Keep the container alive
CMD ["sleep", "infinity"]



# Production Target Stage 
# Normally called without specifying "target" in compose
FROM busybox:glibc

# Create production ready folder for the binaries and change directory
WORKDIR /usr/local/app

# Copy the binaries from the build to the current directory
COPY --from=build /src/app/build .
    
# Execute the app
CMD ["./src/main"]