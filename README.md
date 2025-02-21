# Raster Graphics

**Raster Graphics** is a lightweight, command-line photo editing software written in C++ that allows users to edit and manipulate raster images in `.pbm`, `.pgm`, and `.ppm` formats. The software includes features for transforming images, creating collages, and managing multiple sessions for seamless editing.

## Features

- **Image Transformations**
  - **Rotate Left**: Rotate your image 90° counterclockwise.
  - **Rotate Right**: Rotate your image 90° clockwise.
  - **Negative**: Invert the colors of the image.
  - **Monochrome**: Convert the image into a black-and-white version.
  - **Grayscale**: Convert the image to shades of gray.
  - **Undo**: Roll back any applied transformations to return to the original image.

- **Collages**
  - **Horizontal Collage**: Create a horizontal collage using multiple images of the same format.
  - **Vertical Collage**: Create a vertical collage using multiple images of the same format.

- **File/Session Management**
  - **Load Image**: Load an image from a supported format (`.pbm`, `.pgm`, `.ppm`) to edit in a new session.
  - **Add Image**: Add an image to the current session from a supported format (`.pbm`, `.pgm`, `.ppm`) to edit.
  - **Save/Save As**: Save the progress for all pictures and collages in the session or save as the last picture or collage.
  - **Close**: Close the last picture or collage without saving the progress or close a specific session without saving the progress in the closed session.
  - **Session Management**: Manage multiple sessions, allowing you to load, close, edit, and switch between sessions without losing progress.

- **Command-line Interface**: 
  - Type `>help` to display a list of available commands and how to use them.

## Supported Formats
- **.pbm** (Portable Bitmap)
- **.pgm** (Portable Graymap)
- **.ppm** (Portable Pixmap)

## How to Use

1. **Loading an Image**:  
   Load an image to begin editing. Ensure that the image is in one of the supported formats.
   
2. **Apply Transformations**:  
   Use one or more transformation commands to modify the loaded image.

3. **Creating a Collage**:  
   Create a collage using 2 images of the same format. Choose between a horizontal or vertical layout.
   If the collage is horizontal, they must be the same height.
   If the collage is vertical, they must be the same width.

5. **Undo Last Transformation**:  
   Roll back the most recent transformation applied to the image.

6. **Save the Image**:  
   Save your edited image to your pictures directory.

7. **Switching Between Sessions**:  
   If multiple images are loaded, you can switch between sessions without losing progress in the other images.

8. **Get Help**:  
   Display a list of all available commands with the `>help` command.

## Example Usage

- **Rotate an image and convert to grayscale**:
   1. Load an image.
   2. Apply `rotate right` transformation.
   3. Apply `grayscale` transformation.
   4. Save the resulting image.

- **Create a horizontal collage**:
   1. Load multiple images of the same format.
   2. Create a horizontal collage with the loaded images.
   3. Save the resulting collage.

- **Undo a Transformation**:
   1. Apply the `negative` transformation to an image.
   2. Undo the transformation.
   3. Save the restored image.

## Screenshots

### Example of Negative Transformation:
Before:  
![Before Negative](https://github.com/user-attachments/assets/be128afe-a913-4a89-9b60-c8445efa2a40)



After:  
![After Negative](https://github.com/user-attachments/assets/2cc2d3ed-d239-4a82-a149-61cfbcd34dd8)



### Example of Horizontal Collage:
Before: 
Image1
![Image 1](https://github.com/user-attachments/assets/1828ad35-9aee-4c74-81cf-91c3a0ecbe2d)


Image2
![Image 2](https://github.com/user-attachments/assets/2cc2d3ed-d239-4a82-a149-61cfbcd34dd8)

After:  
![Horizontal Collage](https://github.com/user-attachments/assets/49a0548e-d49a-41bb-a6cb-76ff452e304d)



## Installation

To run **Raster Graphics**, clone this repository and compile the C++ source code using your preferred compiler. Once compiled, you can run the executable and start using the software.

## Contributing

Feel free to fork this repository, submit pull requests, or file issues. We welcome contributions to add more features, optimize performance, or fix bugs!

