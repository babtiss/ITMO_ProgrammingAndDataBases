using System;

namespace Reports.DAL.Entities
{
    public class Report
    {
        public Guid Id { get; private set; }
        public string Context { set; get; }
        public DateTime CreatedOn { set; get; }
        public Guid EmployeeWhoCreated { set; get; }
        public TaskModel TaskModel { set; get; }
        
        private Report()
        {
        }
        public Report(string context, Guid employeeWhoCreated, TaskModel taskModel)
        {
            Id = new Guid();
            Context = context;
            EmployeeWhoCreated = employeeWhoCreated;
            CreatedOn = DateTime.Now;
            TaskModel = taskModel;

        }
        public class RequestReport
        {
            public string Context { set; get; }
            public Guid EmployeeWhoCreated { set; get; }
            public TaskModel TaskModel { set; get; }
        }
        public class RequestReportUpdate
        {
            public Guid Id { set; get; }
            public string Context { set; get; }
            public Guid EmployeeWhoCreated { set; get; }
        }
    }
}