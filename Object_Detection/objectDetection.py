from fastapi import FastAPI, File, UploadFile
import uvicorn
import cv2
import numpy as np
from ultralytics import YOLO
from PIL import Image
import io
import json

# Load YOLOv8 model
model = YOLO("best.pt")

# Load class labels
with open("classes.json", "r") as f:
    CLASS_NAMES = json.load(f)
    CLASS_NAMES = {v: k for k, v in CLASS_NAMES.items()}  # Reverse mapping

app = FastAPI()

@app.post("/predict/")
async def predict(file: UploadFile = File(...)):
    # Read image
    image_bytes = await file.read()
    image = Image.open(io.BytesIO(image_bytes))
    
    # Perform inference
    results = model(image)
    
    # Process results
    detections = []
    for result in results:
        for box in result.boxes:
            x1, y1, x2, y2 = box.xyxy[0].tolist()  # Bounding box coordinates
            conf = float(box.conf[0])  # Confidence score
            class_id = int(box.cls[0])  # Class ID
            class_name = CLASS_NAMES.get(class_id, "Unknown")
            
            detections.append({
                "class": class_name,
                "confidence": conf,
                "bbox": [x1, y1, x2, y2]
            })
    
    return {"detections": detections}

if __name__ == "__main__":
    uvicorn.run(app, host="0.0.0.0", port=8000)