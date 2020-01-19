  computeGeneration(*altGrid, *grid, NUM_ROWS, NUM_COLS);
  display(*grid, &matrix);
  // Red pixel for frame indicator and 0,0 orientation
  matrix.drawPixel(2, 2, matrix.Color333(7, 0, 0));
  matrix.drawPixel(60, 2, matrix.Color333(0, 7, 7));
  // delay(1000);

  computeGeneration(*grid, *altGrid, NUM_ROWS, NUM_COLS);
  display(*grid, &matrix);
  // Blue pixel for frame indicator and 0,0 orientation
  matrix.drawPixel(2, 2, matrix.Color333(0, 0, 7));
  matrix.drawPixel(60, 2, matrix.Color333(0, 7, 7));
  // delay(1000);


}

void display(bool *current, RGBmatrixPanel *myMatrix)
{
  int numPix = 0;
  for (int x = 0; x < NUM_COLS; x++)
  {
    for (int y = 0; y < NUM_ROWS; y++)
    {
      bool *cellIsAlive = current + (x * NUM_ROWS + y);

      uint8_t colorIntensity = *cellIsAlive * 3;
      myMatrix->drawPixel(x, y, myMatrix->Color333(colorIntensity, colorIntensity, colorIntensity));

      numPix++;
    }
  }

  sprintf(buf, "displayed %d pixels\n", numPix);
  Serial.println(buf);
  Serial.flush();
}


