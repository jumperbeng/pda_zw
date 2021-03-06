#include "main.h"

int main(int argc, char** argv){

	if(argc!=2)
		cout<<"You need exactly one lef file and one def file."<<endl;
	
	// Read lef file
	LefDataBase lef_db;
	if (not LefParser::read(lef_db, argv[1])){
		cout<<"Your lef file cannot be read!"<<endl;
		return -1;
	}
	
	// Read def file
	DefDataBase def_db;
	if (not DefParser::read(def_db, argv[2])){
		cout<<"Your def file cannot be read!"<<endl;
		return -1;			
	}
	
	cout<<"############################################"<<endl;
	cout<<"The std_out of our program starts from here."<<endl;
	cout<<"############################################"<<endl;
	
	cout<<"Your files are read successfully!"<<endl;
	cout<<macro_list.size()<<" macros are loaded."<<endl;
	cout<<component_list.size()<<" components are loaded."<<endl;
	//Call your legalization functions here.
		
	
	int x,y;
	double w,h;

	// Add the polygon to a list of polygons
	vtkSmartPointer<vtkCellArray> polygons = vtkSmartPointer<vtkCellArray>::New();
	vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();

	// Setup render window, renderer, and interactor
	vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
	vtkSmartPointer<vtkRenderWindow> renderWindow =vtkSmartPointer<vtkRenderWindow>::New();
	vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	renderWindowInteractor->SetRenderWindow(renderWindow);
	renderer->SetBackground(255.,255.,255.);
	unsigned char black[3] = { 0., 0, 0 };

	for(int i=0;i<10;i++){
		x=component_list[i].get_x();
		y=component_list[i].get_y();
		w=component_list[i].get_w();
		h=component_list[i].get_h();
		cout<<x<<" "<<y<<" "<<w<<" "<<h<<endl;

		double p0[3] = {x, y, 0.0};
		double p1[3] = {x+w, y, 0.0};
		double p2[3] = {x+w, y+h, 0.0};
		double p3[3] = {x, y+h, 0.0};

		// Create a vtkPoints object and store the points in it
		points->Reset();
		points->InsertNextPoint(p0);
		points->InsertNextPoint(p1);
		points->InsertNextPoint(p2);
		points->InsertNextPoint(p3);
		points->InsertNextPoint(p0);

  		vtkSmartPointer<vtkPolyLine> polyLine = vtkSmartPointer<vtkPolyLine>::New();
  		polyLine->GetPointIds()->SetNumberOfIds(5);
  		for(unsigned int i = 0; i < 5; i++){
    			polyLine->GetPointIds()->SetId(i,i);
  		}

		// Create a cell array to store the lines in and add the lines to it
		vtkSmartPointer<vtkCellArray> cells = vtkSmartPointer<vtkCellArray>::New();
		cells->InsertNextCell(polyLine);

		// Create a polydata to store everything in
		vtkSmartPointer<vtkPolyData> polyData = vtkSmartPointer<vtkPolyData>::New();

		// Add the points to the dataset
		polyData->SetPoints(points);

		// Add the lines to the dataset
		polyData->SetLines(cells);

		// Create a vtkUnsignedCharArray container and store the colors in it
		vtkSmartPointer<vtkUnsignedCharArray> colors = vtkSmartPointer<vtkUnsignedCharArray>::New();
		colors->SetNumberOfComponents(4);
		colors->InsertNextTupleValue(black);
		colors->InsertNextTupleValue(black);
		colors->InsertNextTupleValue(black);
		colors->InsertNextTupleValue(black);
	
		polyData->GetCellData()->SetScalars(colors);
 
		// Setup actor and mapper
		vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
		#if VTK_MAJOR_VERSION <= 5
		mapper->SetInput(polyData);
		#else
		mapper->SetInputData(polyData);
		#endif

		vtkSmartPointer<vtkActor> actor =vtkSmartPointer<vtkActor>::New();
		actor->SetMapper(mapper);
	
		renderWindow->AddRenderer(renderer);
		
		renderer->AddActor(actor);
		
		renderWindow->Render();
		
	}
	renderWindowInteractor->Start();
	return EXIT_SUCCESS;
}
