## Create Virtual Environment with myenv
```
python3 -m venv myenv
```

## Activate environment
```
source myenv/bin/activate
```
## Install required packages
```
pip install ultralytics opencv-python matplotlib fastapi uvicorn numpy pillow python-multipart
```

## Command to execute FastAPI run
```
uvicorn main:app --host 0.0.0.0 --port 8000
```
## To test the application run
```
curl -X 'POST' 'http://127.0.0.1:8000/predict/' -F 'file=@image.jpg'
```
